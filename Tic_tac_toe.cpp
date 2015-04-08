/*
J.G
CS570,Spring Semester 2015 (Mar 7)
Solution for Tic-Tac-Toe Assignment.
*/

#include <iostream>
#include <limits> //use cin.ignore(numeric_limits....);

using namespace std;

#define Xs 1 //mark(&role) define
#define Os -1 // in the thinking that IF Os wins, the SUM of line
              //will be -N, Xs wins, sum must equal N
#define N 3 //board size,3*3,scalable, N=3,4,5,6...9 
/*max N=9, because here only 1-digit input is considered*/

class Board //protect the game board, so I use class 
{
	friend std::ostream& operator<<(std::ostream& out, Board& board);
private:
	signed char data[N][N]; //not vector, 
	                        //in the thinking the board dimension 
							//is static not dynamic
public:
	Board()// TO DO: not sure what's the best solution 
		   //to initialize the 2d array in c++
	{
			for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j)
				data[i][j] = 0;
		}
	}

	//save user input into the game board
	void set(char x, char y, signed char val)// 1 for Xs player, -1 for Os
	{
		if (0 <= x&&x <= (N-1) && 0 <= y&&y <= (N-1))
			data[x][y] = val;
		else
			std::cout << "Set Out of Index." << endl;				
	}

	//read board data by row and column
	char read(char x, char y)
	{
		if (0 <= x&&x <= (N-1) && 0 <= y&&y <= (N-1))
			return data[x][y];
		else{
			std::cout << "Read Out of Index." << endl;
			return 0;
		}			
	}

	//ask for user to input and check if the input is valid 
	//or position has been taken
	bool userInput(char& row, char& column)
	{
		char row_c = ' ';
		char column_c = ' ';
		
		cin >> row_c >> column_c;
		int r = row_c - '0';
		int c = column_c - '0';
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (r<1 || r>N || c<1 || c>N){
			cout << "Input Out Range [" <<row_c<<","<<column_c<<"]." <<endl;
			return false;
		}

		row = r - 1;
		column = c - 1;
		if (0 != data[row][column]){
			cout << "Already marked, Try again.." << endl;
			return false;
		}
		else{
			return true;
		}
		
	}

	//check currently if someone win after the board is updated
	bool checkWin(char row, char column, signed char role)
	{
		signed char sum_r = 0, sum_c = 0, sum_win = N*role;//to win, must a line of N

		for (int i = 0; i < N; ++i){
			sum_r += data[row][i];      //'---' win
			sum_c += data[i][column];	//'|'	win
		}
		if (sum_win == sum_r || sum_win == sum_c)
			return true;

		else if ((row == column) || (row + column == N - 1)){
			sum_r = 0; sum_c = 0;
			for (int i = 0; i < N; ++i){
				sum_r += data[i][i];        //'\' win
				sum_c += data[i][N - 1 - i];//'/' win
			}
			if (sum_win == sum_r || sum_win == sum_c)
				return true;
		}

		else
			return false;
	}

};

//output the board to ostream
//scalable, board size N=3,4,5,6,...
std::ostream& operator<<(std::ostream& out, Board& board)
{
	char marks[N][N];
	
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
		switch (board.data[i][j]){
			case Xs:marks[i][j] = 'X'; break;
			case Os:marks[i][j] = 'O'; break;
			default:marks[i][j] = ' '; break;
		}		
	}
	//output board head, body(row by row)
	for (int i = 0; i <N; ++i){ //head:  1   2   3 
		out << "  " << (i + 1) << " ";
	}
	out << endl;	
		
	for (int i = 0; i < (2 * N - 1); ++i)//body
	{
		if ((i % 2) == 0){//row: 1   |   |     
			out << (i/2 + 1);
			for (int j = 0; j < (N - 1); ++j){
				out << " " << marks[i/2][j] << " |";
			}
			out << " " << marks[i/2][N-1] << " " << endl;//end of row
		}
		else{//row:  ---+---+---
			out << " ";
			for (int j = 0; j < (N - 1); ++j){
				out << "---+";
			}				
			out << "---" << endl; //end of row
			}
		}
		
	return out;
}

//Tic-tac-toe
//max steps=N*N, Win or Draw to exit
int main()
{
	char row = 0;
	char column = 0;
	char markcnt = 0;
	bool winflag = false;
	Board board;
	cout << "Welcome to Tic-tac-toe!" << endl;
	cout << "Please input row+column, eg. 11 or 1 1" << endl
		 << "Xs starts:" << endl;
	cout << board << endl;
	cout << "x";
	
	while (1)
	{
		if (board.userInput(row, column)){
			if (markcnt % 2 == 0){//this turn, player is Xs
				board.set(row, column, Xs);//insert player Xs input 
				winflag = board.checkWin(row, column, Xs);
				cout << board << endl ;

				if (true == winflag){
					cout << "Winer is Xs!" << endl;
					break;
				}
				else
					cout << "o"; //remind next player is Os
					
			}
			else{//this turn, player is Os
				board.set(row, column, Os);//insert player Os input 
				winflag = board.checkWin(row, column, Os);
				cout << board << endl;
				if (true == winflag){
					cout << endl << "Winer is Os!" << endl;
					break;
				}
				else
					cout << "x";//remind next player is Xs
			}

			++markcnt;//X O X O X O X O X, game over.
			if (N*N == markcnt){
				cout << "..."<<endl<<"Game Over. You draw!" << endl;
				break;
			}
		}
	}

	return 0;
}
