//update:
//法1：同下面思路用×10+%计算，http://www.geeksforgeeks.org/write-a-c-program-to-reverse-digits-of-a-number/
//法2：用位操作()，如果x的i位为1，则将结果的31-i位置1 http://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);  
   }
    return reverse_num;
}
//法2,还可继续优化，当x变为0之后停止，然后最后向左移位多位。
//此处他们没有判断溢出，也可以用位判断
//---------------------------------------------------------------------------------------------------------------------
//基本问题：将数倒着算的基本方法，是遍历一个数的各位时，同时build它的逆序数字。然后注意最后一步可能溢出

//这里两个算法都是参考的别人的，其中这个比较简洁，利用long long判断是否溢出，这样做不会出现多次overflow后变为好数的原因是
//long long保证比int长，新build的数是long long肯定不会溢出
//另一种算法是抓住某个时刻一旦溢出，那么把这个数倒过去算和上一个结果不一致，则说明溢出。

// 4 other people usually use while(x!=0)
class Solution {
    public: 
    int reverse(int x) {
        long long res = 0;
        while(x!=0){
            res = res*10 + x%10;
            x = x/10;
        }
         
        return (res<INT_MIN || res>INT_MAX) ? 0 : res; // if (ret>0x7fffffff) return 0; //people use overflow check.
    }
};
