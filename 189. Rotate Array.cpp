//别人算法是inplace的互换，是处理的数组，值得学习
//reverse前部分，reverse后部分，再reverse全部

// 如果是数组就要自己移动了，要么inplace，要么复制一个拷贝
// since it's vector, insert + resize

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()||k==0) return;
        int n = nums.size();
        nums.insert(nums.begin(), nums.begin()+ n - (k%n), nums.end());
        nums.resize(n);
    }
};
