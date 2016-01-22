// 别人的算法，更深刻的认识了本题的特性，逢9进一位，直到不是9就可以返回，后面补0；

// what's the range of this number, if it's not overflow, we can get the real number, plus one, then translate it into digits;
// otherwise, we will do this by operating on digits.

#include<iostream>
 #include<vector>
 #include <algorithm>    // std::max
 
 using namespace std;
 


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = digits.size();
        if(k==0) return vector<int>{1};
        if(digits[k-1]<9) {
            vector<int> ans = digits;
            ans[k-1] = ans[k-1] + 1;
            return ans;
        }
        
        bool carry = true;
        vector<int> ans(k+1);
        
        for(int i = k-1; i>=0; i--) {
            int now = digits[i] + carry;
            if(now>=10) {
                carry = true;
                ans[i+1] = now -10;
            } else{
                carry = false;
                ans[i+1] = now;
            }
        }
        
        if(carry) {
            ans[0]=1;
            return ans;
        }else{
            
            return vector<int>(&ans[1], &ans[1]+k);
        }
        
    }
}; 
 
 
void plusone(vector<int> &digits)
{
    int n = digits.size();
    if(n==0) return;
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return;
        }
    }
        digits[0] =1;
        digits.push_back(0);

}
    

int main() {
    vector<int> nums {};
    Solution slu;
    for(int i: slu.plusOne(nums))
    cout<<i<<" ";    
    
    cout<<endl;
    plusone(nums);    
    for(int i : nums)
    cout<<i<<" ";
}
