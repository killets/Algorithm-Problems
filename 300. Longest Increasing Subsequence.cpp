#include<iostream>
 #include<stack>
 #include<vector>
 
using namespace std;

// 此题第一次提交后出错之后想了很久，关键在于最长序列，ans不是递增的，而是最后要遍历一遍
// 找出最大值，作为最终结果。 我错在return ans[n-1]这种思想，把数组当不减数列，以为最后结果就是最后一个。
// Input[1,3,6,7,9,4,10,5,6],错误output7, 把5当作长6，在此基础上增加了1，为7；（错误的）

// dynamic programing: ans[i] = max(ans[i-1], max ans[j] +1 when nums[j]<nums[i])
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       if(n==0) return 0;
       int ans[n]={0};
       ans[0] =1;
       for(int i=1; i<n; i++) {
           int tmp=1;
           for(int j = 0; j<i; j++) {
               if((nums[j]<nums[i]&&ans[j]+1>tmp)){
                   tmp = ans[j]+1;
               }
           }
           ans[i] = tmp;
       }
       
       int max =0;
       for(int i = 0; i<n; i++)
       if(ans[i]>max)
       max = ans[i];
       
       return max;
    }
};

int main() {
Solution slu;
vector<int> in {1,3,6,7,9,4,10,5,6};
cout<<slu.lengthOfLIS(in)<<endl;
    
}
