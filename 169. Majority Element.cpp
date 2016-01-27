// 别人算法比较巧妙，待研究
// WRONG ANSWER input [1], should output 1

// Time Limit Exceeded
// so during insert, check if it already be a majority number
// this will stop in advance hence save some time

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int> m;
       for(int e: nums) {
           unordered_map<int,int>::iterator it = m.find(e);
           if(it==m.end())
            m.insert(make_pair(e,1));
           else{
            it->second++;
            if(it->second>nums.size()/2)
               return it->first;
           }
        }
        return nums.size()==1?nums[0]: -1; // Will not reach here
    }

    int majorityElementOLD(vector<int>& nums) {
       unordered_multimap<int,int> m;
       for(int e: nums) {
           m.insert(make_pair(e,0));
       }
       
       for(int e: nums) {
           if(m.count(e)>nums.size()/2)
           return e;
       }
       
       return -1; // Will not reach here
    }
};
