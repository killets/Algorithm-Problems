#include<iostream>
 #include<stack>
 #include<vector>
 
using namespace std;
// 二分搜索可以找一个特定的数，也可以用来找“局部”最大最小值

// 参考别人算法，可以找局部最大值即可
// 二分搜索或者顺序搜索,O(logn) vs. O(n)

class Solution {
public:
    // sequential search, find a number less than its left
    int findPeakElement_sequential(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1])
            return i-1;
        }
        return nums.size()-1;
    }
    
    //binary search, iterative way
    int findPeakElement_iteration(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi) {
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>nums[mid+1])
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
    
    //binary search, recursive way
    int findPeakElement_recursive(vector<int>& nums, int lo, int hi) {
        if(lo>=hi) return lo;
        int mid = lo+(hi-lo)/2;
        if(nums[mid]>nums[mid+1])
            return findPeakElement_recursive(nums, lo, mid);
        else
            return findPeakElement_recursive(nums, mid+1, hi);
    }
    
    int findPeakElement(vector<int>& nums) {
        return findPeakElement_recursive(nums, 0, nums.size()-1);
    }
    
};

int main() {
Solution slu;
vector<int> in {1,2,3,1,3};
cout<<slu.findPeakElement(in)<<endl;
}
