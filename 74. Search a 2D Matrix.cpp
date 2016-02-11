// 别人算法最高票居然是把matrix当作一维数组，我不用这的原因是当一维数组后，就要在matrix中移动
// matrix读数是二维的，慢，所以我先只读行首，确定行之后，再在行内搜索，这时不会跳行，相当于一维数组，快一些
// 评论中有人懂这个，说别人算法不好，提到了cach hit/miss

//first locate a row, then search in that row; reason is matrix is slower than array
//use binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        
        int lo=0;
        int hi = matrix.size()-1;
        if(matrix[0][0]>target||matrix[hi][matrix[0].size()-1]<target)
        return false;
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(matrix[mid][0]<target)
                lo = mid+1;
            else if(matrix[mid][0]==target)
                return true;
            else
                hi = hi-1;
        }
        
        
        lo = lo-1;
        
        int lo2 = 0; int hi2= matrix[0].size()-1;
        while(lo2<=hi2){
            int mid2 = lo2+(hi2-lo2)/2;
            if(matrix[lo][mid2]<target)
                lo2 = mid2+1;
            else if(matrix[lo][mid2]==target)
                return true;
            else 
                hi2 = mid2-1;
        }
        return false;
    }
};
