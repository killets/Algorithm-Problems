 #include<iostream>
 #include<vector>
 
 using namespace std;
    
// an = max(an-1, an-2 + sn);//sn is current number, so it's sn-1; since a array is added a a0 in front.
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        vector<int> a(n+1);
        a[0]=0;
        a[1]=nums[0];
        for(int i=2; i<=n; i++) {
            a[i]= a[i-1] > (a[i-2]+nums[i-1]) ? a[i-1] : a[i-2]+nums[i-1]; // nums[i] // a[] is one longger than nums[]
        }
        return a[n];
    }

int main() {
    vector<int> nums {2,1,4,5};
    //vector<int> nums {3,5,4};
    cout<<rob(nums)<<endl;
}
