// 别人算法思路是一样的，但简洁一些，简介也有代价，即使用了多余的空间，列+1，行+1， 加在了左边框上，然后
// 设置[0,1]=1就可以使各点均满足和的关系。即补齐了第一行的上，第一列的左。当空间比较有限时就不好了。

// line 25教训是不要优化， if(i/n!=0&& i%n!=0) 而不是paths[i]!=1，直接表达，别拐弯
// if obstacle, then not add that part, or then directly set that point to zero

//based on 62
//典型的dp问题，有左右关系，子问题
//一个点只能被上面或左边的点走一步到达
//50,70 will overflow

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==0||n==0) return 0;
        vector<int>paths(m*n);
        
        if(obstacleGrid[0][0]==1) return 0; // [[1]]
        paths[0]=1;
        
        for(int i=1; i<n; ++i)
            paths[i]= obstacleGrid[0][i]== 1 ? 0 : paths[i-1];
        for(int i=1; i<m; ++i)
            paths[i*n]=obstacleGrid[i][0]==1 ? 0 :paths[(i-1)*n];
        
        for(int i=n+1; i<m*n; ++i)
            if(i/n!=0&& i%n!=0){ // if it's not set
                paths[i] = obstacleGrid[i/n][i%n]==1 ? 0: paths[i-1]+paths[i-n];
            }
        
        return paths[m*n-1];
    }
};
