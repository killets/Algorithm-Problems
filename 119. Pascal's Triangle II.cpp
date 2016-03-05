//别人算法好在从后面开始算。因为从左往右算的时候，每算新的值的时候就把原来该位置上的值抹掉了，那么如果反着算就不存在这个问题
//当然，也可以每次算当前位的时候把当前位保存起来。于是有以下：
//2nd: 还是从左往右算【干扰情况下算了好久，要用到两个tmp】
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        for(int i=0; i<=rowIndex; i++){
            ans[0]=1;
            int tmp1 =1;
            int tmp2 =1;
            for(int j=1; j<i; j++){
                tmp1 = ans[j];
               ans[j]=ans[j]+tmp2; //当前值加上上一个位置的旧值
                tmp2 = tmp1; //记录旧值
            }
            ans[i]=1;
        }
        return ans;
    }
};


// 1st2, every new row only related to last row
// 1st try, calculate all rows but only return the last one
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        vector<int> tmp = ans;
        for(int i=0; i<=rowIndex; i++){
            tmp[0]=1;
            for(int j=1; j<i; j++)
            tmp[j]= ans[j-1]+ans[j];
            tmp[i]=1;
            
            for(int k=0; k<i+1; k++)
            ans[k] = tmp[k];
        }
        return ans;
    }
};
