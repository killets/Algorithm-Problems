//别人算法就是backtracking,此题我写了三种算法

//DP or backtracking or recursive

// TODO: 在此应用中，这三种方法决定谁快谁慢关键之一就是复制比较耗时

// version 3: 21%
// idea of DP is first base: 1, then insert a 2 we have 1,2 or 2,1; then 3,1,2 1,3,2 1,2,3 and ...
// this idea may be not efficient since it involves a lot of vector insert
// DP思想就是由低（少nums）到高建,插入新的元素到已有的组合中去
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<vector<int>>> d(nums.size());
        d[0]={{nums[0]}};
        
        for(int i=1; i<nums.size(); i++){
            for(auto & e: d[i-1])// prior result
                    for(int j=0; j<=e.size(); j++){
                        auto tmp =e;
                        tmp.insert(tmp.begin()+j, nums[i]);
                        d[i].push_back(tmp);
                }
        }
        
        return d[nums.size()-1];
    }
};

//TODO: 我觉得用类似swap的方式，然后引入一个void helper，类似v1，也可以很快；
// version 2, 4% 由v1最快变到非常慢，倒数，原因我猜也是因为复制 
// recursive way
// put an selected element to last position, then permutation(n-1)+that element is answer
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==1)
        return vector<vector<int>>{{nums[0]}};
        
        vector<vector<int>> result;
        for(int i=0; i<nums.size(); i++){
            std::swap(nums[i], nums[nums.size()-1]);
            vector<int> lefts(nums.begin(),nums.begin()+nums.size()-1);
            vector<vector<int>> sub=permute(lefts);
            // if(sub.empty())
            // result.push_back(vector<int>{nums[nums.size()-1]});
            // else
                for(auto & e: sub){
                    e.push_back(nums[nums.size()-1]);
                    result.push_back(e);
                }
            std::swap(nums[i], nums[nums.size()-1]); //这一步也不可少，因为for循环是为了用前面n-1个数，
                                                     //轮流换到最后一位，每次for开始时都要复原原数组，
                                                     //才能表达这个意思；这里不一定说看作是backtracking,
                                                     //而恰好是拿一个出来，表示最后一位有n种可能性；而刚好用
                                                     //了swap这种方式，（其它方式也行，估计会多很多复制），
                                                     //所以看起来是back了。
        }
        
        return result;
    }
};


// version 1： 74%
// backtracking is easy to write, because it use in-place swap
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, result,nums.size()-1);
        return result;
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& result, int pos){
        if(pos==0){
            result.push_back(nums);
            return;
        }
        
        for(int i=0; i<=pos; i++) {
            std::swap(nums[pos],nums[i]);
            helper(nums,result,pos-1);
            std::swap(nums[pos],nums[i]);
        }
        
    }
};
