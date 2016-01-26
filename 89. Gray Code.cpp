// dp, code[i] = change one bit of n bits of code[i-1], (code^=(1<<x)), if not used
// set code[] from 0 to 2^n, done.
// Note: 2 techniques used here, first change x-th bit of a number, num=num^(1<<x)
// second, total number, nth power of 2, 2<<(n-1)

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n<1) return vector<int>{0}; // Overflow limit is not considered
        int N=2<<(n-1);  //Note 1
        vector<int> ans(N);
        vector<bool> hash(N);
        ans[0]=0;
        hash[0]=true;
        for(int i=1; i<N; i++) {
            for(int j=0; j<n; j++) {
                int k = ans[i-1]^(1<<j); //Note 2
                if(hash[k]==false) {
                    ans[i] = k;
                    hash[k] = true;
                    break;
                }
            }
        }
     return ans;   
    }
};
