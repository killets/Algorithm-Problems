连续的subarray，我之前不知道怎么取。
例如 1234567， left ＝ 1.。。k； right ＝ k+1，n， 所以应该也是n^2复杂度
这个是最基本的做法，并没有优化

｀｀｀
A Simple Solution is to use two loops to find XOR of all subarrays and return the maximum.

// A simple C++ program to find max subarray XOR
#include<bits/stdc++.h>
using namespace std;
 
int maxSubarrayXOR(int arr[], int n)
{
    int ans = INT_MIN;     // Initialize result
 
    // Pick starting points of subarrays
    for (int i=0; i<n; i++)
    {
        int curr_xor = 0; // to store xor of current subarray
 
        // Pick ending points of subarrays starting with i
        for (int j=i; j<n; j++)
        {
            curr_xor = curr_xor ^ arr[j];
            ans = max(ans, curr_xor);
        }
    }
    return ans;
}
｀｀｀
