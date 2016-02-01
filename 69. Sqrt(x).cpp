//别人算法有几种方法，其一是binary search，但没有设置lo和hi到小范围，我觉得时间差距在oj上没体现出来的原因是
//32位数，log(32)差不了太多操作；其二是使用 Newton's method / formula; 其三是bit操作，这个不是很理解。
//总体来说，我的算法还不错。 对了，别人处理溢出问题时，比较的是mid与x/mid，在不使用ulonglong条件下不失为好方法。

//记住special case： mid>sqrt(INT_MAX)时mid*mid会overflow

//注意求lo的算法，因为平方根每增加一位，数增加2位，所以/100
//Wrong Answer Input:2147395599 since mid*mid is overflow, try use long long, not work, use u long long

// we can use binary search, the problem is how to find a reasonable start and end number
// my idea is using the number of its digits, 4-digits is 2, 5-digits is 2, 10/2=5,11/2=5;
// lo = 10^(n(x)/2), hi = 10*lo;

class Solution {
public:
    int mySqrt(int x) {
     if(x==0) return 0;
     int lo=1;
     int t=x;
     while(t/100) { //Beautiful!
         lo*=10;
         t=t/100;
     }
     int hi=10*lo;
     while(lo<hi){
         int mid = lo+(hi-lo)/2;
         unsigned long long int tmp = mid*mid; //Fixed here!
         if(tmp<x)
            lo=mid+1;
         else if(tmp>x)
            hi=mid-1;
         else 
            return mid;
     }
     
    return (lo*lo > x) ? lo-1:lo;
    }
};
