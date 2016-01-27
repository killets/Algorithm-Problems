//别人算法也很简洁，移动left指针来指导不重复的元素插在哪，
//当重复时，不动left；

// similar with a problem solved before(delete duplicates in array), two pointers,
// move x[i] to x[i-cnt]

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==val){
                cnt++;
            } else{
                nums[i-cnt]=nums[i];
            }
        }
        return nums.size()-cnt;
    }
};
