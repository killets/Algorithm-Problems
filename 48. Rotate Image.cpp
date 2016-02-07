//别人算法一样，（旋转方式稍有不同）。注意它举一反三到了逆时针旋转
//我一开始就根据右对角线对称的原因是，因为是顺时针旋转，是由一个绕着右对角线的感觉，然后可能发现上下顺序反了，于是再反一下就对了
// -----
//    /』
//   / 』
//思路图https://drive.google.com/open?id=0B0BJAgFiD4jISDdlNklnYm9jRjA
//我凭感觉做的，一试就对了，可能以前见过吧
//我第一想到的是把90度旋转，转换成一系列等效的操作，
//比如沿右下对角线对换，然后水平对换，貌似可以
// test case [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //if(matrix.size()==0) return;
        int n=matrix.size();
        //变换1
        for(int i=0; i<n; i++)
        for(int j=0; j<n-i; j++)//置换一半，不然又还原了
            std::swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            
        cout<<matrix[0][0]<<endl;    
        //变换2    
        for(int i=0; i<n/2; i++) //置换一半，不然又还原了
        for(int j=0; j<n; j++)
            std::swap(matrix[i][j],matrix[n-1-i][j]);
    }
};
