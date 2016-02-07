//别人算法好简单,抓住了最多允许出现2次这一性质，比较当前数和其前面第二个数（result中的），相等说明已存了2次了，
//比它大说明最多存了一次。前面倒数第一个数是否相等不知道。

// wrong answer [1,1], [1,1,2,2]

class Solution {
public:
      int removeDuplicates(vector<int>& nums) {
      int n= nums.size();
      int cnt=0;
      int times = 0;
      for(int i=1; i<n; i++) {
          if(nums[i]==nums[i-1]){
              times++;
              if(times==1){ //第二个数也要拷贝
                  nums[i-cnt]=nums[i];
              }
              cnt++;
          } else{
              if(times>=1){
                cnt--;
                times =0;
              }
              nums[i-cnt]=nums[i];
          }
      }
      return times==0 ? n-cnt: n-cnt+1; // fixed wrong answer
  }
};
