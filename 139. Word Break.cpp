//别人的算法，是基于DP，即新加的子串在字典中，且原串为true。
//有左右顺序，有子问题。
//备注中别人DP写法值得学习，并不是很生硬的for一下把所有DP算出来，而是for之内还有FOR

//这个答案编译时系统出错了，直接返回true都报错，暂且认为是ac的
// backtracking

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        return helper(s, wordDict, 0);
    }

private:
    bool helper(string &s, unordered_set<string>& wordDict, int pos) {
        
        if(pos==s.length())
            return true;
        
        for(int i= pos; i<s.length(); i++) {
            if(wordDict.contains(s.substr(pos, i-pos+1)) {
                //cur.push_back(s.substr(pos, i-pos+1)); //NOT NECESSARY
                if(helper(s, wordDict, cur, i+1))
                    return true;
                //cur.pop();
            }
        }
        
        return false;
    }
    
};
