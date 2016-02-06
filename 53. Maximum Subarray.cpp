// 别人算法看起来好牛逼，待分析。
// 记录DP[]中的最大值，作为返回值！

// 此题我第一次遇到DP的另一种形式，没有DP[N+1]这个状态量，就是max。而且DP的过程不是递归，有什么数学关系，
// 而是通过尝试，比较是否更佳来更新。

//也是由短变长，有左右关系，很典型的DP问题
// 新进来的数如果是负数，则肯定不是；如果是正数，则向左尝试一直到原最佳解的左边界；
// 不能再左，因为如果能左那原解就不是最佳解了。[这个肯定是对的，就看时间够快不了]

// 如果原最佳解是负数，能说明它是一个数，且在n-1序列中完全没有正数，是最大的负数，否则取正数就好了,不会是负解;那么只用比较新加入的数和这个最佳解就完了。

// 只有当是正的时候才有意义连过去

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return INT_MIN;
        
        int max = nums[0];
        int left = 0;
        for(int i=1; i<n; i++){ //DP 从短变长
            if(nums[i]<=0){//如果为负数
                if(nums[i]<=max)//且比max小，那就不管了
                    continue;
                max = nums[i]; //否则，取代max
                left = i;
            } else{// 如果为正数
                int tmp = 0; //朝左找到原最佳的最left边界
                int left_old = left; //因为left会变
                for(int j = i; j>=left_old; j--){
                    tmp+=nums[j];
                    if(tmp>max){ //寻找可能的最大sum
                        max = tmp;
                        left = j;
                    }
                }
            }
            
        }
    
        return max;
            
    }
};
