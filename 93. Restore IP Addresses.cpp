//别人算法除BACKTRACKING外，提到DFS，两者应该有啥联系，待研究。 TODO

//这题是典型的backtracking,试行不行： do, sub, undo
//（backtracking也可以用recursive的方法做）
// test case: "1010010" "0000" 
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        helper(s, result, 0, s.length(), 3);
        return result;
    }
    
private:
    bool check(string & s){
        int i=0;
        while(i<s.length()){
            int num=0;
            if(s[i]=='0' && i<s.length()-1 && s[i+1]!='.')
                return false;// 不能0开头,但可以单独0
    
            while(s[i]!='.'&&i<s.length()){
                num = num*10 +s[i]-'0'; // if start with '0'?
                i++;
            }
        
            if(num>255||num<0) return false;
        
            while(s[i]=='.'&&i<s.length()) i++;
        }
        
        return s[s.length()-1]=='.' ? false :true;
    }
    
    void helper(string& s, vector<string>& result, int pos, int n, int k){
        if(n-pos>3*(k+1)) // too much chars
         return;
        
        if(k<=0){
            if(check(s))
            result.push_back(s);
            return;
        }
        
        for(int i= pos; i<n; ++i) {
            string tmp(s); //do,这里用tmp，避免了undo
            tmp.insert(i+1, "."); // 又错成了pos
            helper(tmp, result, i+2, n+1, k-1); //也是，小心
        }
    }
    
};
