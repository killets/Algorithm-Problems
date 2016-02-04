// TODO: 还不是很快，中等偏下
// 加入hashmap,测试每个位置只用一次unique的值, AC
// version 1
// backtracking is easy to write, because it use in-place swap
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        
        unordered_map<int,int> r; 
        
        for(int i=0; i<=pos; i++) {
            // std::sort(nums.begin(),nums.begin()+pos);
            if(r.count(nums[i])==0){ //Note: this means every position only test unique value
            std::swap(nums[pos],nums[i]);
            helper(nums,result,pos-1);
            std::swap(nums[pos],nums[i]);
                r.insert(make_pair(nums[i],0));
            }
            // while(nums[i+1]==nums[i]) i++;
        }
        
    }
};
