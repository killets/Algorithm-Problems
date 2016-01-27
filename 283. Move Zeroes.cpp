// 别人的思想一样的，不过就是维护插入位置，而不是重复个数

// 和27题去掉特定数思想是一样的，只不过最后补0

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        // move non-zero to front part
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0)
            cnt++;
            else
            nums[i-cnt]=nums[i];
        }
        
        // fill zeros at end of array
        for(int i=0; i<cnt; i++) {
            nums[nums.size()-1-i]=0;
        }
    }
};
