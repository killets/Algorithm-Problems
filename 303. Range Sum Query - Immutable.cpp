// 1 dp idea: sum[2,5] = sum[0,5] -sum[0,2] +num[2] = sum[0,5] -sum[0,1];

include<iostream>
 #include<vector>
 #include <algorithm>    // std::max
 using namespace std;
 
class NumArray {    
private:
    vector<int> * sum;
    bool empty;
public:
// complexity = O(n)
    NumArray(vector<int> &nums) {
        int k = nums.size();
        sum = new vector<int>(k);
        if(k==0) {
            empty=true; 
            return;
        }
        else{
            empty = false;
        }
        (*sum)[0]=nums[0];
        for(int i = 1; i<k; i++) {
        (*sum)[i] = (*sum)[i-1] + nums[i];
        }
    }
// O(1)
    int sumRange(int i, int j) {
        if(empty) return 0;
        if(i==0) return (*sum)[j];
        return (*sum)[j]-(*sum)[i-1];
    }
};
    

int main() {
    vector<int> nums {3,4,5,5};
    NumArray a(nums);    
    cout<<a.sumRange(0,2)<<endl;
    cout<<a.sumRange(2,3)<<endl;
}
