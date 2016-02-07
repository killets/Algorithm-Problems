//别人这个算法看起来好cool，待研究。TODO
//好像是说能够到达最远的超过last就能到last,可是怎么证明一定能够刚好踩点到达last而不超过?

// 我的想法是倒着推，要想到达最后一步，那么看上一步有哪些能到，
// 于是问题转化为起点能不能到上一步的那个点，只要有一种方案能到就可以。
// 于是这是个DP问题

class Solution {
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, nums.size()-1);
    }
    
private:
    bool helper(vector<int>&nums, int des){
        //我想的是先直接考虑起点到终点一步到达，不行再说
        if(des <= nums[0])
        return true;
        
        for(int i=des-1; i>0; i--){ //这里我想的是i==0已经上面考虑过了
            if(des-i<=nums[i]){
                return helper(nums, i); // 最后会问0能不能到某个数如1，或者2，3,不会问谁能到0
            }
        }
        
        return false;
    }
};
