//别人算法思路和我一样，但又有很大不同，它是bottom up，在于它的行是倒着算，而行内是顺着，也避免了O(N)时用到两个o（n）防止旧值被覆盖,和119一样，
//而且倒着看有个很大的便利，是相当于已知两个子节点，来更新父节点。
//图片参见： https://drive.google.com/open?id=0B0BJAgFiD4jIS0pFVEFRY1RmNlE

// top down
//Bonus says only O(n) extra space,
// since we just use last row above,we can store them in two o(n) array and update it 
// 1. two O(n) array
// 2. one o(n) array, but from right to left NOTE: 和119一样，倒着算
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> path(n);
        path[0]=triangle[0][0];
        for(int i=1; i<n; i++) {
            for(int j=i; j>=0; j--) {//关键
                int min = INT_MAX;
                //别人算法优化了这里，肯定存在子节点，就直接两个求min
                if((j-1)>=0 && path[j-1]<min) min = path[j-1];//左边一个
                if(j<i && path[j]<min) min = path[j];//对齐
                //if((j+1)<i && path[i-1][j+1]<min) min = path[i-1][j+1]; //右边一个 not adjacent
                path[j] = min + triangle[i][j];
            }
        }
        
        int min = path[0];
        for(int i=1; i<n; i++){
            if(path[i]<min) min = path[i];
        }
        
        return min;
    }
};


// my first thought is using backtracking to find the smallest path in all possible path;
// however, tag shows it's Dynamic Programming
// what's confused me here is what's the meaning of adjacent numbers
// we need to store an array with the same struture of input triangle

class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> path = triangle;
        for(int i=1; i<triangle.size(); i++) {
            for(int j=0; j<path[i].size(); j++) {
                int min = INT_MAX;
                if((j-1)>=0 && path[i-1][j-1]<min) min = path[i-1][j-1];
                if(j<i && path[i-1][j]<min) min = path[i-1][j];
                //if((j+1)<i && path[i-1][j+1]<min) min = path[i-1][j+1]; // not adjacent
                path[i][j] = min + triangle[i][j];
                //cout<<path[i][j]<<" __ ";
            }
            cout<<endl;
        }
        
        int n = triangle.size()-1;
        int min = path[n][0];
        for(int i=1; i<path[n].size(); i++){
            //cout<<path[n][i]<<" ";
            if(path[n][i]<min) min = path[n][i];
        }
        
        return min;
    }
};
