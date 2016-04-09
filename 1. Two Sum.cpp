//别人的插入直接用的hash[nums[i]]=i;
//这里值得学习的是，并不是一开始就遍历所有的数放入hash map中，而是边找边放
//手头上读到一个新数nums[i]，那么首先尝试在hash map中寻找target-nums[i]是否已有，有的话，那刚好凑成一对，返回结果；
//没有的话，这个新数可能被后面的数利用，于是插入map中。
//如此，最多遍历所有数字,o(n)， space o(n)
//更正，o(n^2); 实际上，unordered_map find复杂度Complexity
//Average case: constant.
//Worst case: linear in container size.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> res;
      unordered_map<int, int> hmap;
      
      for(int i=1; i<= nums.size(); i++){
              auto it = hmap.find(target - nums[i-1]);
              if(it!=hmap.end()){
               res.push_back(it->second);
               res.push_back(i);
               return res;
              }
              else
               hmap.insert(make_pair(nums[i-1],i));
          }
          
      return res;
    }
};
