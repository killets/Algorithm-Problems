// 别人算法，use xor, 0^x =x, x^x=0, x^y^y = x;

// insert and toggle one element by element in hash map, then check the single one

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      unordered_map<int, bool> hash;
      for(int i=0; i<nums.size(); i++) {
          std::unordered_map<int, bool>::iterator it = hash.find(nums[i]); 
          if (it != hash.end())
            it->second = false;
          else
            hash.insert(std::make_pair(nums[i],true));
      }
      
      for(auto & it: hash) {
          if(it.second==true){
              return it.first;
          }
      }
      return 0; // for empty input
    }
};
