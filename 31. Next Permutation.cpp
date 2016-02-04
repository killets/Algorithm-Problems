// 别人算法，思路和我是一样的，不过更加精炼，而且用reverse代替sort，复杂度会降低
// 思路图：https://drive.google.com/open?id=0B0BJAgFiD4jIYUE0RDl6NnZlUU0

void nextPermutation(vector<int> &num) {
    if(num.size()<=1) return;
    int i=num.size()-1,j;
    for(j=num.size()-2; j>=0; j--){
        if(num[j]<num[j+1]) break;
    }
    if(j>=0){
        while(num[i]<=num[j]) i--;
        std::swap(num[i], num[j]);
    }
    std::reverse(num.begin()+j+1, num.end());
}

//-------------------------------------------------------------------------------------
// basic idea is to find a rule to solve this problem, no special algorithm idea
// test case
// [3,2,4,3,5] [3,2,4,5,3] [3,2,5,4,3]  [3,2,1,4,3] 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        if(n>=2 && nums[n-2]<nums[n-1]){
                std:swap(nums[n-2], nums[n-1]);
                return; //#1
        }
        
        int i=n-3;
        while(i>=0){
            int min_greater = nums[i];
            int j=i+1;
            while(nums[j]>nums[i]&&j<n){
                min_greater=nums[j];
                j++;
            }
            if(min_greater!=nums[i]) { // find a greater number to swap
                std::swap(nums[i],nums[j-1]); // j-1 since j++
                std::sort(nums.begin()+i+1,nums.end());
                return; //#2
            } else
                i--;
        }
        if(i==-1)// all digits are in decending order, no more to borrow
            std::sort(nums.begin(), nums.end()); //#3
    }
};
