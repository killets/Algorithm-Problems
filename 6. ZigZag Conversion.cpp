//将标签贴在数字上，然后相同标签的归到一行；遇到1则标签递增；遇到n则标签递减；直到数字读完

// update: 
// be careful with zigzag pattern, number of nodes between two coloums changes with the numRows
// my solution is take every char in s and put into right row, the key is use k+=step
// to control the change of row;

class Solution {
public:
    string convert(string s, int numRows) {
        // if 1 row or string is too short 
        if(numRows==1 || numRows>=s.length()) return s;
        // store char in rows
        vector<char> rows[numRows];
        int step=0; // control row change
        for(int i=0, k=0; i<s.length(); ++i) {
            rows[k].push_back(s[i]); //push s[i] into right row
            if(k==0) // if head, row++;
                step=1;
            if(k==numRows-1) // if tail, then go back, row--;
                step=-1;
            k+=step;// update row
        }
        
        // build result string 
        string res = s;
        int j=0;
        for(int i=0; i<numRows; i++) {
            for(auto e: rows[i]){
                res[j++]=e;
            }
        }
        return res;
    }
};

// 我旧的算法看起来更好，直接按照规律存数， 一段来回有2n-2个数，然后判断去还是回
        vector<char> zigzagS[numRows];
        for(int i=0 ; i<sz; i++){
         int p = i%(2*numRows-2); 
         /* for every position in s, find a row in pattern array
          [0, 1, 2, ... n-1; n-2 , n- 1, ...1] to store the char s[p] */
         zigzagS[p < numRows ? p : 2*numRows-2-p].push_back(s[i]); //判断是去还是回程
        } 
        
// 别人的思想，（我也这样想到过），是并非逐个取string中字符放到各个row中，而是直接按row然后跳跃离散的在string中取到应有的元素
//这样完全是one pass，更快
