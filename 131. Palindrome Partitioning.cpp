//别人算法一致，backtracking
// 2nd, try backtracking，速度差不多靠前了
// 1st is too slow
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        helper(s, ans, cur, 0);
        return ans;
    }

private:
    void helper(string s, vector<vector<string>>& ans, vector<string>& cur, int pos){
        if(pos==s.length()){
            ans.push_back(cur);
            return;
        }
        
        for(int i=pos; i<s.length(); i++){
            string subs = s.substr(pos, i-pos+1);
            if(check(subs)){
                cur.push_back(subs);
                helper(s, ans, cur, i+1);
                cur.pop_back();
            }
        }
    }
    
    bool check(string &s){
        int start=0;
        int end = s.length()-1;
        while(start<end&&s[start]==s[end]){
            start++;
            end--;
        }
        return s[start]==s[end];
    }
};

//这个跑下来特别慢，倒数
//a, sub
//aa, sub
// aba, sub
//how to find palindrome, use check

class Solution1 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(check(s,0,i)){
                string curs = s.substr(0, i+1);
                string subs= s.substr(i+1,n-i-1);
                vector<vector<string>> sub = partition(subs);
                if(subs.empty()){
                    //return vector<vector<string>> {{curs}};
                    ans.push_back(vector<string>{curs});
                } else {
                    for(vector<string> & e : sub){
                        e.insert(e.begin(), curs);
                        ans.push_back(e);
                    }
                }
            }
        }
        
        return ans;
    }

private:
    bool check(string &s, int start, int end){
        while(start<end&&s[start]==s[end]){
            start++;
            end--;
        }
        return s[start]==s[end];
    }
};
