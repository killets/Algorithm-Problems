//别人算法利用递归，https://drive.google.com/file/d/0B0BJAgFiD4jIbGdEcWU4aHcydWM/view?usp=sharing
//别人总结了几种算法，https://leetcode.com/discuss/52800/5-different-choices-when-talk-with-interviewers
//别人评论中提到，n=INT_MIN时的特殊情况，这时候-n的值不对

//Wrong Answer, n=-3

// idea is from wikipedia, same as CPE593
// x^2  x^4 x^8, x^8*x=x^9

class Solution {
public:
    double myPow(double x, int n) {
        int sign=1;
        bool n_nagative= (n<0); // Wrong answer fixed
        if(n_nagative) n=-n;
        if(x<0) {
            x=-x;
            if(n%2==1)
            sign=-1;
        }
        
        double ans=1;
        while(n) {
            if(n%2==1) //Always will enter this
            ans*=x; //Note!
            x=x*x;  // Note!
            n=n/2;
        }
        ans*=sign;
        
        return n_nagative? 1/ans: ans;
    }
};
