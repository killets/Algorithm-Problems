/*
J.G
CS570, Spring 2015 (Mar 30)
Solution for Tic-Tac-Toe Assignment 2
Tic-Tac-Toe 2.0

Declare:
ClearScreen() is from http://www.cplusplus.com/forum/articles/10515/
to replace system("cls");
*/

#include <iostream>
#include <vector>  // for board: 2d array
#include <chrono>  // for time
#include <string>  // for marks: X O A B C
#include <fstream> // log.txt
#include <sstream> // for split getline()
#include <thread>  // for c++ 11 sleep
#include <cstdint> // for uint64_t time
#include <windows.h> //for CleanScreen(), min(),

using namespace std;

#define ERROR_INPUT 0
#define VALID_INPUT 1
#define SAVE_EXIT 2
#define GAME_COMPLETED 0
#define GAME_UNCOMPLETED 1
#define GAME_EMPTY 2

const string symbol = "XOABCDEFGHIJKLMNPQRSTUVWYZ";
const char space = '\0'; // default value of un-marked board
const string game_done[2] = { "win_flag: 0", "win_flag: 1" };

/*helper functions for Tic_game class*/
namespace  
{   
	/*Follow: log.txt -> Tic_game.lines -> vector<gstep> */

	//game step
	struct gstep{ 
		int steps;
		int row;
		int col;
		char val;
		std::uint64_t dtn; //time used @ this step
	};

	//log single step into Tic_game's self log system: lines
	vector<std::string>& logstep(vector<string>& lines, gstep step)
	{
		ostringstream outline;
		outline << "steps: " << step.steps << " row: " << step.row << " col: " << step.col
			<< " value: " << step.val << " duration(ms): " << step.dtn;
		string ss = outline.str();
		lines.push_back(ss);
		return lines;
	}

	//translate .lines to plain data 
	vector<gstep>parase_log(vector<string> lines)
	{
		gstep step;
		vector<gstep> gamelog;
		
		for (auto e : lines){
			std::istringstream ss(e);
			string tp;
			ss >> tp;
			if (tp == "steps:"){
				ss >> step.steps
					>> tp >> step.row
					>> tp >> step.col
					>> tp >> step.val
					>> tp >> step.dtn;
				gamelog.push_back(step);
			}
		}

		return  gamelog;
	}

	// When board size >=10*10, use this function to get user input,
	// helper function of Tic_game::get_input
	int get_input_int(string ss)
	{
		int r;
		bool bad = false;
		do{
			cout << ss;
			cin >> r;
			bad = cin.fail();
			if (bad)
				cout << "Error TYPE." << endl;
			cin.clear();
			// max() conflics with windows.h
			// cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			
			cin.ignore(100, '\n');
		} while (bad);
		return r;
	}

}
/*Board is a private part of a game. It stores what you see on the game board.*/
class Board 
{
	friend class Tic_game;
	friend std::ostream& operator<<(std::ostream& out,const Board & board); 
public:	
	Board();
	Board(int n);
	
	void set(int x, int y, char val);
	char get(int x, int y) const;
	int get_size(void) const;
	//for square-win:
	void get_maxsame_InRow(int row, int column, char role, int& cnt_l, int& cnt_r) const;
	void get_maxsame_InCol(int row, int column, char role, int& cnt_u, int& cnt_d) const;
	void rotate_col2row();
	void rotate_col2row_back();

private:	
	vector<vector<char>> data;
	int N;
};

/* Tic_game represents TIC-TAC-TOE GAME. 
   It includes board, rules, methods needed to play.
*/
class Tic_game
{
	friend std::ostream& operator<<(std::ostream& out,const Tic_game & game);
public:	
	Tic_game();
	Tic_game(int u_playernum, int u_N, int u_winN);

	int  get_input(int& row, int& column);
	char get_currplayer() const;
	bool add_step(int row, int column, std::chrono::milliseconds& dtn);
	bool isWin(int row, int column, char role);
	bool isWin_rowCol(int row, int column, char role) const;
	bool isWin_diagonal(int row, int column, char role, bool isslash) const;
	bool isWin_square(int row, int column, char role) const;
	bool isWin_square_fup(int row, int column, char role, int cnt_l, int cnt_r) const; //helper fucntion
	bool isWin_square_fdown(int row, int column, char role, int cnt_l, int cnt_r) const; //helper fucntion
	int loadgame(string fileName);
	void savegame(string fileName, bool iscompleted);
	void replay() const;
	void demo() const;

private:
	Board board;
	int playernum;
	int N;     // boardSize
	int winN;  // win sequence cnt
	int steps = 0 ; //current move
	bool winflag = false;
	vector<string>lines;
};


/*------------------------Board class-----------------------------------------------------*/
Board::Board()
{
	N = 3;
	data = vector<vector<char>>(3, vector<char>(3));
	for (int i = 0; i < 3; ++i){
		data[i].resize(3);
	}
}

Board::Board(int n)// TO DO: not sure what's the best solution 
// to initialize the 2d array in c++
{
	N = n;
	data = vector<vector<char>>(n, vector<char>(n));
	for (int i = 0; i < n; ++i){
		data[i].resize(n);
	}
}

// Put user-input into the game board
void Board::set(int x, int y, char val)
{
	if (0 <= x && x < N && 0 <= y && y < N)
		data[x][y] = val;
	else
		std::cout << "Error: Set Out of Index." << endl;
}

// Read board data by row and column
char Board::get(int x, int y) const
{
	if (0 <= x && x < N && 0 <= y && y < N)
		return data[x][y];
	else{
		std::cout << "Error: Read Out of Index." << endl;
		return space;
	}
}

int Board::get_size() const
{
	return N;
}

// Return the max combo number in horizontal  
void Board::get_maxsame_InRow(int row, int column, char role, int& cnt_l, int& cnt_r) const
{
	int i = column;
	while (role == data[row][i]){
		cnt_r++;
		++i;
		if (i >= N)	break; // CAUTION: error prone (vect[N] OUT Boundary)
	}

	i = column;
	while (role == data[row][i]){
		cnt_l++;
		--i;
		if (i < 0) break;// CAUTION: error prone (vect[-1] OUT Boundary)
	}

}

void Board::get_maxsame_InCol(int row, int column, char role, int& cnt_u, int& cnt_d) const
{
	int i = row;
	while (role == data[i][column]){
		cnt_u++;
		--i;
		if (i < 0) break;
	}

	i = row;
	while (role == data[i][column] && i <N){
		cnt_d++;
		++i;
		if (i >= N) break;
	}

}

void Board::rotate_col2row()
{
	Board board_new(N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board_new.data[j][N - 1 - i] = data[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			data[i][j] = board_new.data[i][j];
}

void Board::rotate_col2row_back()
{
	Board board_new(N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board_new.data[N - 1 - j][i] = data[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			data[i][j] = board_new.data[i][j];
}

/*------------------------Tic_game class---------------------------------------------------*/

Tic_game::Tic_game()
	:playernum(2), N(3), winN(3), board(Board(3))
{
}

Tic_game::Tic_game(int u_playernum, int u_N, int u_winN)
	: playernum(u_playernum), N(u_N), winN(u_winN), board(Board(u_N))
{
}

char Tic_game::get_currplayer() const
{
	return symbol[steps % playernum];
}

// Ask user to INPUT and check if the input is VALID 
// or position has been MARKED
// Return: Save_exit, or valid_input, or invalid input
int Tic_game::get_input(int& row, int& column)
{
	int r = 0, c = 0;
	char row_c = ' ', column_c = ' ';
	
	if (N >= 10){
		// cin >> int (used to be char)
		cout << "...\nInput method changed, since N>=10" << endl;
		r = get_input_int("Please input row number:(0 to save_exit)");
		c = get_input_int("Please input col number:(0 to save_exit)");

		if (0 == r && 0 == c)
			return SAVE_EXIT;
	}
	else{
		cin >> row_c >> column_c;
		r = row_c - '0';
		c = column_c - '0';

		cin.clear();		
		cin.ignore(100, '\n');

		if ('S' == row_c && 'S' == column_c)
			return SAVE_EXIT;
	}

	if (r<1 || r>N || c<1 || c>N){
		if (N>=10)
			cout << "Error: Input Out Range [" << r << "," << c << "]." << endl;
		else
			cout << "Error: Input Out Range [" << row_c << "," << column_c << "]." << endl;
		return ERROR_INPUT;
	}

	row = r - 1;
	column = c - 1;
	if (space != board.data[row][column]){
		cout << "Warning:: Marked, Try again..." << endl;
		return ERROR_INPUT;
	}
	else{
		return VALID_INPUT;
	}

}

// Add lastest step into game and check whether produce a WIN
bool Tic_game::add_step(int row, int column, std::chrono::milliseconds& dtn)
{
	int player_now = steps % playernum;
	gstep pstep = { steps, row, column, symbol[player_now], dtn.count() };
	// add new line log
	lines = logstep(lines, pstep);
	// insert player's input
	board.set(row, column, symbol[player_now]); 
	// check win?
	winflag = isWin(row, column, symbol[player_now]);
	// update display
	cout << board << endl;

	if (winflag){
		cout << "Winer is " << symbol[player_now] <<"."<< endl;
		return false;
	}
	else
		cout << "Player "<<symbol[(steps + 1) % playernum] << ": (input)"; // remind next player is Os
	
	// check tie?
	++steps;
	if (N*N == steps){
		cout << "...\nGame Over. You tied!" << endl;
		return false;
	}

	return true;
}


// Check if someone win after the lateast step,
// Hollow-SQUARE-win is included.
// Every step is responsible for itself win
bool Tic_game::isWin(int row, int column, char role)
{
	/* win in a row  */
	/* win in a column */
	if (isWin_rowCol(row, column, role))
		return true;

	/* win in backslash diagonal */
	if (isWin_diagonal(row, column, role, false))
		return true;

	/* win in slash diagonal */
	if (isWin_diagonal(row, column, role, true))
		return true;

	/* win in square */
	// point is on horizontal line
	if (isWin_square(row, column, role))
		return true;

	// point is on vertical line
	// rotarate columns to rows, so can reuse isWins_square function
	board.rotate_col2row();
	if (isWin_square(column, N - 1 - row, role)) {
		board.rotate_col2row_back();
		return true;
	}
	else
		board.rotate_col2row_back();

	return false;
}

// winN in a row or col
bool Tic_game::isWin_rowCol(int row, int column, char role) const
{
	int combo_r = 0;
	int combo_c = 0;

	/* win in a row --- */
	for (int i = 0; i < N; ++i){
		if (role == board.data[row][i]){
			combo_r++;
			if (winN == combo_r)
				return true;
		}
		else
			combo_r = 0;
	}
	/* win in a column | */
	for (int i = 0; i < N; ++i){
		if (role == board.data[i][column]){
			combo_c++;
			if (winN == combo_c)
				return true;
		}
		else
			combo_c = 0;
	}

	return false;
}

// winN in diagonal: slash & back_slash TWO MODES
bool Tic_game::isWin_diagonal(int row, int column, char role, bool isslash) const
{
	//  slash(backslash): start from left_down corner(left_up).
	int a = isslash ? min((N - 1 - row), column) : min(row, column); 
	//end right_up conner (right_down)
	int b = isslash ? min(row, (N - 1 - column)) : min((N - 1 - row), (N - 1 - column));
	
	if ((a + b + 1) >= winN){ // there is enough room to win
		vector<char> test;

		for (int i = a; i >0; --i){
			if (isslash)
				test.push_back(board.data[row + i][column - i]);
			else
				test.push_back(board.data[row - i][column - i]);
		}
		test.push_back(board.data[row][column]);
		for (int i = 1; i <= b; ++i){
			if (isslash)
				test.push_back(board.data[row - i][column + i]);
			else
				test.push_back(board.data[row + i][column + i]);
		}
		int combo_diagonal = 0;
		for (auto e : test){
			if (role == e)
			{
				combo_diagonal++;
				if (winN == combo_diagonal)
					return true;
			}
			else
				combo_diagonal = 0;
		}
	}

	return false;
}


/*
   Given a mark, Return whether a hollow square is formed nearby.

  1. A square is a 4 sided figure with two pairs of parallel lines: 
                                            up & down, left & right 

					       ........  parallel line 
					              
                        cnt_l   cnt_r 
		         this*     --*-----     up_side (_)
					       - Sqaure   
           left_side(|)    -      -   right_side(|)     
					       --------       
						   down_side(_)

  2. cnt_l = identical marks around its left, similarly, cnt_r (right)
  2. first, in horizontal should: cnt_l+cnt_r-1 >= winN-1; 
  3. then, check parallel line  (flip up & flip down)
  4. check left line ('|'direction), then check right line

  NOTE: here only consider points in the horizontal lines,
        points in vertical can be seen as horizontal by rotating the board
*/
bool Tic_game::isWin_square(int row, int column, char role ) const
{
	if (winN <= 2) {
		cout << "Warning: Win by (1*1)square is not allowed." << endl; 
		return false; 
	}

	// only if there is enought room can we have the chance to suqare-win 
	if ((4 * (winN - 2) - 1)*playernum + 1 > N*N) 
		return false;

	// current point (row, column)
	int cnt_l = 0, cnt_r = 0;  // identical marks around current point	
	// Can it forms a continus line in row direction? 
	board.get_maxsame_InRow(row, column, role, cnt_l, cnt_r); 

	if ((cnt_r + cnt_l - 1) >= (winN - 1)){
		/* FLIP UP. Can forms a square? */
		if (isWin_square_fup(row, column, role, cnt_l, cnt_r))
			return true;
		/* FLIP DOWN. Can forms a square? */
		if (isWin_square_fdown(row, column, role, cnt_l, cnt_r))
			return true;
	}

	return false;
}

// Helper function of isWin_square: check if square is formed above this point 
bool Tic_game::isWin_square_fup(int row, int column, char role, int cnt_l, int cnt_r) const
{
	/* Flip UP */

	// Look for a paired side above it
	if (row - (winN - 2) >= 0){
		int cnt_l2 = 0, cnt_r2 = 0; // flip up
		board.get_maxsame_InRow(row - (winN - 2), column, role, cnt_l2, cnt_r2);

		int left = min(cnt_l, cnt_l2);
		int right = min(cnt_r, cnt_r2);
		// up & down(*itself) sides are paired

		if ((left + right - 1) >= (winN - 1)){
			// then check whether left & right sides is okay
			for (int j = column - left + 1; j + winN - 2 <= column + right - 1; ++j){
				int cnt_left_right = 0;
			
				for (int i = row; i >= row - (winN - 2); --i){ // horizontal move to fix   
					if (role == board.data[i][j] && role == board.data[i][j + winN - 2]){
						cnt_left_right++;
					}
				}
				// left & right side is ok
				if (winN - 1 == cnt_left_right){					
						// finally, up-down left-right sides are both paired
						// ->square is done!
						return true;
				}
			}
		}
	}

	return false;
}

// Helper function of isWin_square: check if square is formed bellow this point 
bool Tic_game::isWin_square_fdown(int row, int column, char role, int cnt_l, int cnt_r) const
{
	/* Flip DOWN */

	// Look a paired side bellow it
	if (row + (winN - 2) < N){
		int cnt_l3 = 0, cnt_r3 = 0; // identical mark number in left, right
		board.get_maxsame_InRow(row + (winN - 2), column, role, cnt_l3, cnt_r3);

		int left = min(cnt_l, cnt_l3);
		int right = min(cnt_r, cnt_r3);
		// up & down(*itself) sides are paired
		if ((left + right - 1) >= (winN - 1)){
			// then check if left & right sides is okay
			for (int j = column - left + 1; j + winN - 2 <= column + right - 1; ++j){  // horizontal move to fix   

				int cnt_left_right = 0;				
				for (int i = row; i <= row + (winN - 2); ++i)
				{
					if (role == board.data[i][j] && role == board.data[i][j + winN - 2]){
						cnt_left_right++;
					}
				}
				// left & right side is ok
				if (winN - 1 == cnt_left_right){				
					return true;
				}
			}
		}
	}
	return false;
}

void Tic_game::replay() const
{
	Board temp_board(N);

	vector<gstep> gamelog = parase_log(lines);
	if (gamelog.empty())
		cout << temp_board;
	cout << endl << "------ REPLAY ------" << endl;
	for (auto e : gamelog){
		temp_board.set(e.row, e.col, e.val);// insert player Xs input
		
		cout << "Step[" << e.steps << "], Player[" << e.val << "], Wait " << e.dtn << "ms ->"<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(e.dtn));
		cout << "Player " << e.val << " input " << e.row + 1 << e.col + 1 << endl;
		cout << temp_board;
	}
	cout << "---- END REPLAY ----" << endl << endl;
}

void Tic_game::demo() const
{
	Board temp_board(N);
	temp_board.set(0, 0, 'x');

	string wait = "\n...............\n";
	for (unsigned int i = 0; i < wait.size(); ++i){
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		cout << wait[i];
	}
	
	string demo = "\n--- This is a demo ---\nPlayer X: (input) 11 \n";
	for (unsigned int i = 0; i < demo.size(); ++i){
			std::this_thread::sleep_for(std::chrono::milliseconds(80));
			cout << demo[i];
		}
	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	cout << temp_board;
	string start = "Now let's start!\n ";
	for (unsigned int i = 0; i < start.size(); ++i){
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
		cout << start[i];
	}
	cout << endl<<board;
}

int Tic_game:: loadgame(string fileName)
{
	std::ifstream infile(fileName);
	std::string input,winstring;
	std::getline(infile, input);// steps, board size, win sequence [rule]
	std::getline(infile, winstring);// winflag
	while (std::getline(infile, input)) // game history
		lines.push_back(input);
	infile.close();


	vector<gstep> gamelog = parase_log(lines);
	for (auto e : gamelog){
		board.set(e.row, e.col, e.val);// update board
		// cout << board;
	}

	if (winstring == game_done[1]){
		//lines.clear();		
		return GAME_COMPLETED;
	}
	else
	{
		if (gamelog.size() > 0)
			steps = gamelog[gamelog.size() - 1].steps + 1;// CAUTION: erroe prone (empty log)
		else{
			cout << "Warning:: Empty Game log found..." << endl;
			steps = 0;
			return GAME_EMPTY;
		}
				
		return GAME_UNCOMPLETED;
	}			
}

void Tic_game::savegame(string fileName, bool iscompleted)
{
	lines.insert(lines.begin(), game_done[iscompleted]);
	
	std::ostringstream ss;
	ss << "player_num: " << playernum << " board_N: " << N << " win_cnt: " << winN;
	lines.insert(lines.begin(), ss.str());

	ofstream outfile(fileName);
	if (!outfile.is_open())	{
		cout << "Error: Can't write file.\n";		
	}
	else{
		for (auto e : lines)
			outfile << e << '\n';
		outfile.close();
	}
}


// output the board to ostream
// scalable, board size N=3,4,5,6,...
std::ostream& operator<<(std::ostream& out, const Board & board)
{
	int N = board.get_size();

	/* output board's head */
	for (int i = 0; i <N; ++i){ // Head: like 1   2   3 ...
		out << "  " << (i + 1) << " ";
	}
	out << endl;

	/* output board's body */
	for (int i = 0; i < (2 * N - 1); ++i){ // body part:row A+row B
		if ((i % 2) == 0){ // Row A:  like  1   |   |   |     
			out << (i / 2 + 1);
			for (int j = 0; j < (N - 1); ++j){
				if (N >= 10 && (i / 2 + 1) >= 10 && j==0)
					out << " " << board.data[i/2][j] << "|";
				else
					out << " " << board.data[i/2][j] << " |";
			}
			out << " " << board.data[i/2][N-1] << " " << endl;// end of row
		}
		else{// Row B: like  ---+---+---
			out << " ";
			for (int j = 0; j < (N - 1); ++j){
				out << "---+";
			}
			out << "---" << endl; // end of row
		}
	}

	return out;
}

std::ostream& operator<<(std::ostream& out, const Tic_game & game)
{
	out << game.board;
	return out;
}


/*--------------------Free functions NO relationship with class----------------------------------*/

/* free functions in main */
namespace
{
	struct Rule
	{
		int player_num;
		int board_N;
		int win_cnt;
		char resum_y_n;
	};

	Rule load_rule(string fileName, bool& res_state)
	{
		std::ifstream infile(fileName);
		string input;

		Rule r_rule = { 2, 3, 3, 'y' }; // default rule
		if (std::getline(infile, input)){
			std::istringstream ss(input);
			string tp;
			ss >> tp;
			if (tp == "player_num:")
				ss >> r_rule.player_num
				>> tp >> r_rule.board_N
				>> tp >> r_rule.win_cnt;
			else{
				cout << "Error: File formate error. Start a new game." << endl;
				res_state = false;
			}				
		}
		else{
			cout << "Error: Problems with file. Start a new game." << endl;
			res_state = false;
		}
		infile.close();
		return r_rule;
	}

	bool check_rule(const Rule & rule)
	{
		if (rule.player_num >= 2 && rule.player_num <= 26 && rule.win_cnt >= 3 && rule.board_N >= 3)
			if ((rule.player_num*(rule.win_cnt - 1) + 1) <= rule.board_N*rule.board_N){
				cout << "Rule Check Passed..." << endl;
				return true;
			}
		cout << "Error Rule. At least [2] players, [3]*[3] board, [3] sequence to play,\n"
			<< "or Game NEVER win..exit..." << endl;
		return false;
	}

	int get_input_int2(string ss)
	{
		int r;
		bool bad = false;
		do{
			cout << ss;
			cin >> r;
			bad = cin.fail();
			if (bad)
				cout << "Error TYPE." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		} while (bad);
		return r;
	}

	bool init_rule(string fileName, Rule& rule)
	{
		//cout << "Press [Y] to resume, [Else] to start new game:";
		cout << "Press [Y/Else] to resume or start new game:";
		cin >> rule.resum_y_n;
		bool load_rule_state = true;

		if ('y' == rule.resum_y_n || 'Y' == rule.resum_y_n){
			rule = load_rule(fileName, load_rule_state);
			if (load_rule_state)				
				return true;
			else
				rule.resum_y_n = 'n';
				
		}

		//if above has input 10, then 0 will pass to player_num.
		cin.clear();
		cin.ignore(100, '\n');
		
		rule.player_num = get_input_int2("How many players are playing: ");
		rule.board_N = get_input_int2("How large the board should be: ");
		rule.win_cnt = get_input_int2("What the win sequence count should be: ");
		
		return check_rule(rule);
	}

	Tic_game init_game(string filePath, bool& return_state)
	{	
		string welcome="Welcome to Tic-Tac-Toe 2.0 !\nFeatures: [Replay] \
+ [Hollow Square] + [Input Error Check]\n          +[Quick Input](row: 1 col: 2£¬just input 12).\n";
		for (unsigned int i = 0; i < welcome.size(); ++i){
			std::this_thread::sleep_for(std::chrono::milliseconds(40));
			cout << welcome[i];
		}

		Rule rule = { 2, 3, 3, 'n' }; // default rule
		if (!init_rule(filePath, rule))	{
			rule = { 2, 3, 3, 'n' };
			return_state = false;
		}

		Tic_game mygame(rule.player_num, rule.board_N, rule.win_cnt);

		if (true == return_state){

			if ('y' == rule.resum_y_n || 'Y' == rule.resum_y_n){
				int log_state = mygame.loadgame(filePath);
				if (GAME_EMPTY == log_state){
					return_state = false;
					return mygame;
				}
					
				else{
					cout << "Press [Y/Else] to replay STEP BY STEP, or directly show the Final board:";
					char ans1;
					cin >> ans1;
					if ('y' == ans1 || 'Y' == ans1)
						mygame.replay();
					else
						cout << '\n' << mygame << endl;

					if (GAME_COMPLETED == log_state){
						cout << "Warning: This game is completed. You must start a new one." << endl;
						return_state = false;
						return mygame;
					}
				}
			}
			else
				mygame.demo();

			cout << endl<< mygame.get_currplayer() << ": (every time Input a 2-digit number\n"
				 <<"    like [11] to play, or [SS] to Save_Exit) "; // remind next player
		}

		return mygame;
	}

	/* Declare:
	   ClearScreen() is from http://www.cplusplus.com/forum/articles/10515/
	   to replace system("cls");
	*/
	void ClearScreen()
	{
		HANDLE                     hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD                      count;
		DWORD                      cellCount;
		COORD                      homeCoords = { 0, 0 };

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return;

		/* Get the number of cells in the current buffer */
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		/* Fill the entire buffer with spaces */
		if (!FillConsoleOutputCharacter(
			hStdOut,
			(TCHAR) ' ',
			cellCount,
			homeCoords,
			&count
			)) return;

		/* Fill the entire buffer with the current colors and attributes */
		if (!FillConsoleOutputAttribute(
			hStdOut,
			csbi.wAttributes,
			cellCount,
			homeCoords,
			&count
			)) return;

		/* Move the cursor home */
		SetConsoleCursorPosition(hStdOut, homeCoords);
	}

    void keep_window_open()
	{
		cin.clear();
		cout << "Please Enter a character to Exit Tic-Tac-Toe 2.0 ...\n";
		char ch;
		cin >> ch;
		return;
	}

}

//TODO: no

int main()
{  
	string filePath = "log.txt";
	bool game_continue = true;
	// Ask resume or not, set rules, check rules, replay
	Tic_game mygame = init_game(filePath, game_continue);
	if (false == game_continue){
		keep_window_open(); // Avoid fleeting
		return 0;
	}
       // timer
	std::chrono::system_clock::time_point tp, tp2;
	std::chrono::milliseconds dtn;
	tp = std::chrono::system_clock::now();

	while (1)
	{
		int row = 0, column = 0;		
		int userin = mygame.get_input(row, column);		
		if (VALID_INPUT == userin){
			 ClearScreen();
			 tp2 = std::chrono::system_clock::now();
			 dtn = std::chrono::duration_cast<std::chrono::milliseconds>(tp2 - tp);
			 tp = tp2;
			 if (!mygame.add_step(row, column, dtn)) {
				 mygame.savegame(filePath, true);
				 cout << "Game Completed & Saved!" << endl;
				 break;
			 }
				 
		 }
		else if (SAVE_EXIT == userin){
			mygame.savegame(filePath, false);
			cout << "..." << endl << "Game Saved!" << endl;	
			break;
		 }
	}

	keep_window_open();
	return 0; 
}