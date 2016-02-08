//别人算法，此题完全可以用iterative方法解， 100题完成！！！TODO
//我的想法是sub recursive方法，等于这一位+后面的子问题的substring
//读清楚题目

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return string();
        return helper(strs, 0);
    }
    
private:
    string helper(vector<string>& strs, int pos){
        char x = (strs[0].length()-1<pos)?0:strs[0][pos];
        if(x==0) return string();
        for(auto&e:strs){
            if(e.length()-1<pos || e[pos]!=x)
            return string();
        }
        return x+helper(strs, pos+1);
    }
};
