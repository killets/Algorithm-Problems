// 这里bucket的思想很重要，有点indirection的味道，通过bucket将不同的nums转到bucketId里面，
//相等于找duplicates了，回到了其基础问题，217 o(n)复杂度

//如果 find insert 这些是o(1),那么就是o(n)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long, long> map;
        int n = nums.size();
        if(n<2 || t<0 || k<=0) return false;
        int w = t+1;
        for(int i=0; i<n; i++){
            if(i>k)
                map.erase((nums[i-k-1]-long(INT_MIN))/w);
            //cout<<long(nums[i]-INT_MIN);
            long bucketId = (nums[i]-long(INT_MIN))/w;
            //cout<<bucketId<<endl;
            if(map.find(bucketId)!=map.end()) //这个决定了一个bucket中只有一个元素，一旦有多个就true了
                return true;
            if(map.find(bucketId-1)!=map.end() && abs(map[bucketId-1]-nums[i])<=t)
                return true;
            if(map.find(bucketId+1)!=map.end() && abs(map[bucketId+1]-nums[i])<=t)
                return true;
            map.insert(make_pair(bucketId, nums[i]));
        }
        return false;
    }
};


//Time Limit Exceeded O(nk)
class Solution_Bruteforce {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
     int n = nums.size();
     if(n<2 || t<0) return false;
     for(int i=0; i<n; i++) {
         for(int j=1; j<=k && i+j<n; j++){
             // assert t is >=0
             if(abs(nums[i]-nums[i+j])<=t)
                return true;
         }
     }
     return false;
    }
};
