//别人算法更精炼；把一个数反转（重新构建），然后比较是否和原数相等，是则为回文字。
//我应该首先站在高层去想解决方法，而不是最底层比较特征。

// 2 use digit number to compare; but I think it uses more space than 1
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<=9) return true;
        long long sz = 1;
        
        int y = x;
        while(y!=0) {
             sz*=10;
             y/=10;
        } // closet greater 10^sz;
        sz = sz/10;  // highest digit base
        
        while(sz>=10) {
            int hi = x/sz; // hi digit
            int lo = x%10; // lo digit
            if(hi!=lo)
            return false;
            x = (x - sz* hi)/10; // delete hi digit by subdition, lo by divide
            sz/=100; // since has deleted 2 digits
        }
        
        return true;
    }
};

// 1 not allow to_string
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) x = -x;
        std::string s = std::to_string(x);
        int sz = s.length();
        for(int lo = 0, hi = sz -1 ; hi >= lo; ++lo, --hi) {
            if(s[lo] != s[hi])
            return false;
        }
        return true;
    }
};
*/
