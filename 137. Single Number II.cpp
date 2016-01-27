// 此题用hashmap的做法不是最佳答案，因为题目要求不使用额外空间；
// 只有使用bit 操作可以达到此效果；参考答案采用的是模拟三进制。

 int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto e: nums) {
            unordered_map<int,int>::iterator it=m.find(e);
            if(it==m.end()) {
                m.insert(std::make_pair(e,1));
            }else
                it->second ++;
        }
        
        for(auto e:m) {
            if(e.second==1)
            return e.first;
        }
        return 0;
    }
};
