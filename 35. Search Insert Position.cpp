//别人算法看起来和二分搜索差不多，但区别在于没有相等时的return，借此找到有重复时最小index的那个
//我记得找局部最大（小）也用二分

//本来还想着用helper调用的，写完意识到不需要，一次AC!
// binary search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        if(target<=nums[lo])
            return lo;
        else if(target>nums[hi])
            return hi+1;
        else if(target==nums[hi])
            return hi;
            
        while(lo<hi){    
            int mid = lo +(hi-lo)/2;
            if(nums[mid]>target){
                hi = mid-1;
            } else if(nums[mid]==target){
                return mid;
            } else {
                lo = mid+1;
            }
        }
        
        return nums[lo]<target? lo+1: lo;
    }
    
// private:
//     int helper(vector<int>& nums, int low, int hi, int target){
//     }
    
};
