// 自己想出来的！和别人比更清晰 
// N*N 独占不共线

// 我的思路是用backtracking, 从第一个子放起，k=0, 第k个子只能放在第k行，所以不会有row重合；
// 然后避免多个子在同一column，则使用col向量标记； 避免在同一对角，则分为左对角和右对角，
// 注意对角是指斜线，并不是对角线
// 问题的实质，是N*N的坐标中，巧好N个点(过程中可以少于N)，任意两点不共线，共线的方式是row，column，左diagonal，右diagonal；
// 那么每一个子需要独占一个row（k）, column, left diagonal, right diagonal
// 这样可以大大简化isVaild的判断。


// backtracking
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur(n, string(n,'.'));
        vector<bool> col(n);  // 判断列是否占用
        vector<bool> lDiag(2*n-1);  // ‘/对角’是否已占用
        vector<bool> rDiag(2*n-1);  // ‘\对角’
        helper(res, cur, col, lDiag, rDiag, 0, n);
        return res;
    }
    
    void helper(vector<vector<string>>& res, vector<string>& cur, vector<bool>& col,
                            vector<bool>& lDiag, vector<bool>& rDiag, int k, int n){
        if(k==n){
            res.push_back(cur);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(col[i]==false && lDiag[k+i]==false && rDiag[n-1-k+i] == false){
                cur[k][i] = 'Q';
                col[i] = true;
                lDiag[k+i] = true; // 对斜线进行编号
                rDiag[n-1-k+i] = true;
                
                helper(res, cur, col, lDiag, rDiag, k+1, n);
                
                cur[k][i] = '.';
                col[i] = false;
                lDiag[k+i] = false;
                rDiag[n-1-k+i] = false;
            }
        }
    }
    
    // not used
    bool isValid(int i, int k, vector<bool>& col, vector<bool>& lDiag, vector<bool>& rDiag, int n){
        return (col[i]==false && lDiag[k+i]==false && rDiag[n-1-k+i] == false);
    }
    
};

int test()
{
    Solution slu;   
    auto r = slu.solveNQueens(8);
    cout<<r.size()<<endl;
    for(auto s : r){
        for(auto ss: s){
            cout<<ss<<endl;
        }
        cout<<endl;
    }
    return 0;
}
