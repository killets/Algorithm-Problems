//别人算法的思想是，例如计算30/4
// 4翻倍得8，8翻倍得16，16翻倍得32>30，所以回退到16， 30=16+...., 16=4*[4]
// 剩余30-16=14，计算14/4, 
// 4翻倍8，8翻倍16，回退到8， 14=8+。。。， 8=4*[2]
// 剩余30-16-8=6，计算6/4
// 4翻倍8，8>6,回退到4，6=4+...., 4=4*[1]
// 剩余6-4=2， 2<4, 2=2*[0], done!
// result = [4]+[2]+[1]+[0]=7
// 相当于30= 16+8+4...2

// 同样考虑符号位；
// 另外，overflow的情况不止我想的一种，divdsor=0;
// 第二种是，divdend=INT_MIN; 因为INT_MIN取绝对值为1，不是相反数；

// Time Limit Exceeded

// my idea is translate all numbers into positive,
// then use sum of divisor of cnt times, 
// result is related to cnt.

class Solution {
public:
    int divide(int dividend, int divisor) {
        //some special case
         if(divisor==1) return dividend;
         else if(dividend==0) return 0;
         else if(divisor==0) return INT_MAX;
        // change to positive form    
        bool sym = false;
        if(dividend<0) {dividend=0-dividend; sym=~sym;}
        if(divisor<0) {divisor=0-divisor;sym=~sym;}
        // add multiple times
        int cnt=0;
        int sum=divisor;
        while(sum<dividend){
            sum+=divisor;
            if(sum<0)
            cout<<"Overflow";
            cnt++;
        }
        // (-)14/7 cnt=1; so need cnt+1
        // expected ans -13/7 =-1...-6; not -2...1, so be careful when sym = true
        if(sym) return sum==dividend? 0-cnt-1:0-cnt;
        else return sum==dividend? (cnt+1): cnt;
    }
};

int main() {
Solution slu;
cout<<slu.divide(2147483647,2)<<endl;
}
