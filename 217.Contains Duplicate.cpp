//收获：从最简单想起，逐渐改进
//这里用set不用map

// naive way is o(n^2) compare every elment with others behind it
// a better way is sorting ,then only compare neighbours o(nlogn)
// if space is not an problem, we can use hash, if find return true, otherwise insert
// and if the integers has a small range, we can use bitset to do this
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> bag;
        for(auto e: nums){
            if(bag.find(e)!=bag .end())
                return true;
            bag.insert(e);
        }
        return false;
    }
};

