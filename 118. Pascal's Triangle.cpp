//别人算法，快在一开始就定义好了数组长度，没有用push_back。问题在于我解题时想到了怎么能动态，ans[i]的长度为i。
// 别人是用resize实现的。

//改进：也成了最快的
//改进不判断numRows为0的情况，放在for中
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++) {
            vector<int> tmp(i+1);
            tmp[0]=1;
            for(int j=1; j<i; j++)
            tmp[j] = ans[i-1][j-1]+ans[i-1][j];
            tmp[i]=1; //tmp[0]=tmp[i]=1
            ans.push_back(tmp);
        }
        return ans;
    }
};
//居然非常慢
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows<=0) return vector<vector<int>>(); //有点多余
        vector<vector<int>> ans{vector<int>{1}};
        for(int i=1; i<numRows; i++) {
            vector<int> tmp(i+1);
            tmp[0]=1;
            for(int j=1; j<i; j++)
            tmp[j] = ans[i-1][j-1]+ans[i-1][j];
            tmp[i]=1;
            ans.push_back(tmp);
        }
        return ans;
    }
};
