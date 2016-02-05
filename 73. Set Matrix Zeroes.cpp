// in place思路，找已有的空间存想存的信息。
// 别人算法，很巧妙地考虑了in place 这一要求，把行的状态存在行的开头，列的状态存在列的开头，
// 然后第一行第一列要存两个状态，于是设置了一个另外的变量存列状态；
// 在遍历设置完状态后，倒叙set各个cell的值；因为状态量是这一行（或列）的最后一个数，所以倒序时
// 不会影响到该行或列的其它元素。

// 另一个的算法https://leetcode.com/discuss/21206/my-c-o-1-yoooooo，是把列的信息存到一个行为0的行里面去。
// 这个算法要跑几次遍历，相比较还是前述存行首列首方法好，后面倒序时相当于根据十字坐标来设置cell的值。

// 1st idea is to loop through the whole matrix one time to find all zeros and record them, then 
// according to this record to set zeros one by one, in worst case it uses O(mn) space;
// 1st.a idea is similar but only record the row id and coloumn id, so worst O(m+n) space;

// 2nd, if you really want it in place, I think it may bring somehow bad impact on speed.
// loop matrix to find a number that not used in it, then loop again to mark zeros to that number
// third loop again if it's that number, mark all values in that row and collmun to 0 if cell is not that number
// fourth loop reset that marker to zero 【我的算法太慢了】

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int firstColumn=1; // sate of first column
        for(int i=0; i<matrix.size(); i++){ // save state in matrix head
            if(matrix[i][0]==0)
            firstColumn=0;
            
            for(int j=1; j<matrix[0].size(); j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
            }
   
        }
        
        for(int i=matrix.size()-1; i>=0; i--) // according the state set elements in reverse order
        for(int j=matrix[0].size()-1; j>=0; j--){ //别人算法这里是把J==0单独拿出来，和我上面写的一样。
            if(j==0){
                if(firstColumn==0)
                matrix[i][0]=0;
            } else{
                if(matrix[i][0]==0||matrix[0][j]==0)
                matrix[i][j]=0;
            }
        }
    }
};
