//别人算法是从bit操作那种2^n引申开来，怎么处理单个元素出现多次的情况，k次，则可以把这个元素加到结果中{不加，1个，2个，。。， k个}，然后
//跳到下一个不同的元素。
//细想一下，别人的算法其实是DP，把一个相同的元素整体作为DP的一个过程，下一个直接是考虑加上k个相同元素时，从DP:n-1到DP:n;
//那么保存原来的结果在final result中，即新元素不取，若取得话，新元素出现k次，则在原结果中加1个，2个，。。k个新元素，形成的新数组加入到
//final result 中去，作为DP的一个结果。继续考虑下一个新元素，若有的话。

//我的也是最快的！[但从结构上考虑用backtracking要用到栈，比DP慢;] 

//第一个出现的可以拿后面的，然后跳过所有相同的
//这种题目别人思想一种是利用bit操作，2^n个数； 另一种就是backtracking。我采用的后者。
//注意两点，一是helper里面的for用不用，2是里面的while的位置。

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<int> input;
     vector<vector<int>> result;
     std::sort(nums.begin(), nums.end());
     //result.push_back(vector<int>());
     helper(nums, result, input, 0);
     return result;
    }
private:
    void helper(vector<int> & nums, vector<vector<int>> & result, vector<int> & input, int i){
        if(i==nums.size()){
         result.push_back(input);
         return;
        }   
        
        //for(int i=pos; i< nums.size(); i++){
            //take this number
            input.push_back(nums[i]);
            helper(nums, result, input, i+1);
            
            // not take
            input.pop_back();
            while(nums[i]==nums[i+1] && i< nums.size()-1){ //Note 把while从后面拿到前面就对了！！！
                i++;
            }
            helper(nums, result, input, i+1);
            
        //}
        
    }
};
