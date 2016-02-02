// 别人算法各种各样，后续需要研究。

// backtracking
// Note : input digits should not contain "1", expected answer return null
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        string cur="";
        helper(digits, cur, result, 0);
        return result;
    }
private:
    static const string symbol[8];
    
    void helper(string digits, string& cur, vector<string>& result, int pos){
        if(pos==digits.length()) {
            result.push_back(cur);
            return;
        }
        int i=pos;
        //for(int i=pos; i<digits.length(); i++){
            for(int j=0; j<symbol[digits[i]-'2'].length(); j++){
                string tmp =cur;
                tmp += symbol[digits[i]-'2'][j];
                helper(digits, tmp, result,i+1);
                //cur=cur.substr(0,cur.length()-1);
            }
        //}
    }
    
};

const string Solution::symbol[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
