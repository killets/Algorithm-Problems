//别人算法用的思想是组合逻辑，此题终点方向是一个对角线，那么需要走m-1个下，n-1个右，
//而恰好走的步子只能是向下或向右，即只能前进不能返回，因此在m+n-2步中取m-1， 为C..
//于是直接用公式算即可，复杂度o(n)

//我的dp算法，我觉得更通用，而且简单，没有阶乘运算，只有加，算一个就存起来，后面只管加，
//复杂度度o(n)
//排名第二的也是dp算法，而且发现了有些值可以不用保存，进一步优化空间复杂度

//典型的dp问题，有左右关系，子问题
//一个点只能被上面或左边的点走一步到达
//50,70 will overflow
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        vector<int>paths(m*n);
        
        for(int i=0; i<n; ++i)
            paths[i]=1;
        for(int i=0; i<m; ++i)
            paths[i*n]=1;
        
        for(int i=n+1; i<m*n; ++i)
            if(paths[i]!=1)
            paths[i] = paths[i-1]+paths[i-n];
        
        return paths[m*n-1];
    }
};
