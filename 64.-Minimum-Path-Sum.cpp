//别人算法思路相同，但只存左边一列信息，动态向右更新，节约空间复杂度O(n)而不是o(m*n)

//greedy algorithm
// dp: min = min{ last state + final step} = min{left, up} + grid
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> minS(m*n);
        minS[0]=grid[0][0];
        for(int i=1; i<n; i++)
        minS[i] = minS[i-1]+grid[0][i];
        for(int j=1; j<m; j++)
        minS[j*n] = minS[(j-1)*n] + grid[j][0];
        
        for(int i=1; i<m; i++)
        for(int j=1; j<n; j++){
            minS[i*n+j] = std::min(minS[i*n+j-1],minS[(i-1)*n +j]) +grid[i][j]; 
        }
        
        return minS[m*n-1];
    }
};
