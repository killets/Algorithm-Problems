// 别人算法思想是，把数向右逐次移位，只比较最右边的第0位是否是1，当数为0时即停止。

// warning: suggest parentheses around comparison in operand of '&'

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        for(int i=0; i<32;i++){
            //if(n&(1<<i)!=0)  // Wrong Answer : 1
             if((n&(1<<i))!=0) 
                cnt++;
        }
        return cnt;
    }
};
