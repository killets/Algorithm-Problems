// 别人算法非常棒，因为n个数有2^n种组合，（n个数分别取还是不取），那么刚好取或者是不取，就用1,0来表示；
// 于是有了位操作，其结果就是这n位数，是0还是1。每一个数代表了一种组合方式。
// 那么可以， for(int i=0 ; i<2^n; i++) { 解析i的各位bit，从低到高i位，为1就把对应的nums存入该组合方式中去}

// 我的做法：这个题还是比较巧妙的利用了现有程序，因为数集是distinct的，比如【1，3，4，6】可以看作是【1，2，3，4】，用index来表示值
// 导致的结果可能比别人算法直接解要慢

//可以基于77做，返回k=0，到n所有的结果
//然后返回时将index改为对应nums的值
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for(int k=1;k<=nums.size(); k++){
            vector<int> com(k);
            helper(result, com, nums.size(), k);
        }
      
        // 因为题目给的是nums，不是1～n,但是可以当作排序的是其index，这样最后把结果改成index对应的函数值即可
        std::sort(nums.begin(), nums.end());
        for(auto & e: result)
        for(auto & ee: e){
            ee = nums[ee-1];
        }
        result.push_back(vector<int>());
        return result;
    }
    
private:
    void helper(vector<vector<int>>& result, vector<int>& com, int max, int k){
        if(k==0){
            result.push_back(com);
            return;
        }
        
        for(int i=max; i>=1;i--){
            if(i < k)  //有要足够多的数，填完剩余的位数
            return;
            com[k-1] = i; //填当前位
            helper(result, com, i-1, k-1);
        }
    }   
    
};
