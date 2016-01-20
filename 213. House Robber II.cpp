// 2 since a0 and a1 are the same old rober problem, we can make it a helper function; then
//  result = max {old(0, n-2), old(1,n-3)+nums[n-1]};
//  see: https://leetcode.com/discuss/36544/simple-ac-solution-in-java-in-o-n-with-explanation

// 1 dp idea: when it has cycle, it can be viewed as two no cycle problem, a0,n and a1,n; 
//  if nums[i] not taken, then nums[0] can be taken, then result = a0,i-1; If taken, then
//  nums[0] not taken, nums[i-1] not taken, then result = a1,n-2 + nums[i];
//  final result = max of above.

#include<iostream>
 #include<vector>
 #include <algorithm>    // std::max
 
 using namespace std;
    
// an = max(an-1, an-2 + sn);//sn is current number, so it's sn-1; since a array is added a a0 in front.
    int rob1(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        vector<int> a(n+1);
        a[0]=0;
        a[1]=nums[0];
        for(int i=2; i<=n; i++) {
            a[i]= a[i-1] > (a[i-2]+nums[i-1]) ? a[i-1] : a[i-2]+nums[i-1]; // nums[i] // a[] is one longger than nums[]
        }
        return a[n];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        else if(n==1) return nums[0];
        else if(n==2) return std::max(nums[0],nums[1]);
        else if(n==3) return std::max(std::max(nums[0], nums[1]), nums[2]);
        else {
        vector<int> a0(n); // old rober, no cycle, array from 0,to n
        vector<int> a1(n); // old rober, no cycle, array from 1,to n
        vector<int> c0(n); // new rober, with cycle
        
        a0[0] = nums[0];
        a0[1] = std::max(nums[0],nums[1]);
        a0[2] = max(nums[1], nums[0] + nums[2]);
        
        a1[0]=0;
        a1[1]=nums[1];
        a1[2]=max(nums[1], nums[2]);
        
        for(int i=3; i<n; i++) {
        a0[i] = max(a0[i-1], a0[i-2]+nums[i]);
        a1[i] = max(a1[i-1], a1[i-2]+nums[i]);
        c0[i] = max(a0[i-1], a1[i-2]+nums[i]);
        }
        
        return c0[n-1];
        }
    

int main() {
    vector<int> nums {3,4,5,5};
    cout<<rob(nums)<<endl;
}
