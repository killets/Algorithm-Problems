// 这个题我想了好久，今天终于克服掉了，完全自己想的！
// 别人的算法跟我完全一致，简写为 dp[i]+= dp[j-1]*dp[i-j], for j = 1 to i
// 视频解析：https://drive.google.com/open?id=0B0BJAgFiD4jIQXZNekZheGJ6dlk
//思路图：https://drive.google.com/open?id=0B0BJAgFiD4jIN0haeWpfYnFRSDg

// 上面第二种思路引导出了目前的想法，recursive的想法，即给定n, 则选定一个root后可以递归为2个子问题，
// left子问题解*right子问题解作为此root的解，然后该root可以从1到n,因此答案为sum{root(i)，i=1 to n}
// 更permutation有点不同的是，所有的数都不能缺省，即root选定后，比如若还剩下一个数大于root，则该数必须挂在右子位置

// use DP to permutate then do check
// check every node if it small or greater than its parents, and the parents exist
// use 0 to store null, 1,2,...n, 0, 0, 0, 0,0,0.... (total 2^n-1)
// 第一种思想是先permutation，在过程中判断当前位和其父节点是否符合BST大小关系，符合才继续下去，这样不用遍历所有的
// 情况； 
// 第二种思想是，确定一位之后，其左右子节点的关系也确定了，左右子取值的范围就缩小了，因此也可以减少遍历。
//  问题在于2^n个位置，要记录的话空间复杂度非常高，而结果不要求返回具体结构，只要数量，所以可以想办法简化。 
//  如果选择的左右子不为0，则要继续挂下一级。直到所有1～n挂完。


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++){
            int sum = 0;
            for(int j=1; j<=i; j++){
                int left = dp[j-1];
                int right = dp[i-j]; // NOTE! total number is i, not n in every loop
                sum += left*right;
            }
            dp[i] = sum;
        }
        
        return dp[n];
    }
};



/*class Solution2 {
public:
    int numTrees(int n) {
    
    }
    
private:
    bool check(vector<int>& nums){
        for(int i=3; i<=nums.size()-2; i+=2){
            if(nums[i]>nums[i/2] || nums[i+1]<nums[i/2])
            return false;
        }
        return true;
    }



    int helper(vector<bool>& nums, int& cnt, int root){
        if(pos==0){
            
            if(check(nums)){
                
            }
 
            return;
        }
        
            nums[root-1] = true;
            
            for(int j= 1; j<root; j++)
                helper(nums, cnt-1, j);
                
            for(int k=root+1; k<=n; k++)
                helper(nums, cnt-2, k);
            
            nums[root-1] = false;

    }   
};*/
