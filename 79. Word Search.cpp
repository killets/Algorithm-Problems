//我的算法很复杂，不够模式化，即这种写法不像标准答案。
//别人算法就是用DFS，然后用辅助矩阵标记访问轨迹防止重复访问形成圈。很赞！
//第二种算法，同上，但直接改board，不使用额外空间。

// step 3: fix wrong answer, since only can move to neighbors not diagonal. //["ab","cd"]"abcd"
// not enough fast, because it continues to search even have found, so return in that case to stop early. //["aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"]
//"baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
// ADD preGuess checks to speed up to fix the error of "Time Limit Exceeded"

class Solution {
private: bool found = false;    
bool allVisited(vector<vector<bool>>& visited){
            int m = visited.size(); 
        int n = visited[0].size();
    for(int i= 0; i< m; i++)
    for(int j = 0;j<n; j++)
    if(visited[i][j] == false)
    return false;
    
    return true;
}

// DOES BOARD HAVE ENOUGH CHARACTORS?
bool preGuess(vector<vector<char>>& board, string& word) {
    int table[52]={0};
    for(vector< vector<char> >::iterator  a = board.begin(); a!= board.end(); a++)
    for(vector<char>::iterator b= a->begin(); b!= a->end(); b++)
    table[*b-'a'>=0 ? 26+*b-'a' :*b-'A']++;
    
    for(int i = 0; i<word.length(); i++)
    if(table[word[i]-'a'>=0? 26+word[i]-'a': word[i]-'A']<=0)
        return false;
    else
       table[word[i]-'a'>=0? 26+word[i]-'a': word[i]-'A']--;
    
    return true;
}
  
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word == "")
    		return false;

        int m = board.size(); 
        int n = board[0].size();
        
        if(word.length()>m*n)
         return false;
        
        if(!preGuess(board, word)) {
            //cout<<"Not possible(no enough chars.)"<<endl;
           return false;
        }
        
        //bool visited[m][n] = {false};
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i< m; i++)
        for(int j =0; j<n; j++){
        helper(board, word, i,j,0, visited);
            if(found)
            return true;
        }
        return found;
    }
    
    void helper(vector<vector<char>>& board, string word, int i, int j, int p,vector<vector<bool>>& visited) {
        if(p<word.length()&&board[i][j] == word[p] && visited[i][j] ==false) {
            visited[i][j] = true;
            
            if(p==word.length()-1){
                // cout<<"found!"<<endl;
                found = true;
                return;
            }
        
            // up down and diagonal
           /* for(int row = i-1; row<=i+1 && row <  (int)board.size(); row++)
            for(int col = j-1; col<=j+1 && col <  (int)board[0].size(); col++)
            if(row>=0&&col>=0) {       
            helper(board, word, row, col, p+1, visited);  
    
                if(found)
                return;
            }*/
            
            // not include diagonal
            int row[4] ={i-1, i+1, i, i};
            int col[4] ={j, j, j-1, j+1};
            for(int k=0; k<4; k++){
            if(row[k]>=0&&row[k]<(int)board.size()&&col[k]>=0&&col[k]<(int)board[0].size())
             helper(board, word, row[k], col[k], p+1, visited);  
            
                if(found)
                return;
            }
            // if(i-1>=0) {
            //      helper(board, word, i-1, j, p+1, visited);
            //      //if
            // }
            // if(i+1<=(int) board.size()-1)
            //     helper(board, word, i+1, j, p+1, visited);
            // if(j-1>=0)
            //      helper(board, word, i, j-1, p+1, visited);
            // if(j+1<=board[0].size()-1)
            //      helper(board, word, i, j+1, p+1, visited);
                 
                 
                 
            visited[i][j] = false;
        }
    }
    
};
