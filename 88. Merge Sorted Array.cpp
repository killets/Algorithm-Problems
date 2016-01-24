// 别人的算法，好在于充分理解了nums1的空间足够hold住两个数组这一特性，巧妙的从后面向前比较；
//  ××××××××--------------
//  ++++++
// 这样不需要额外的数组存结果，再拷贝

// basic idea: double pointer
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j =0;
        vector<int> ans(m+n);
        int k=0;
        while(i<m&&j<n) {
            if(nums1[i]<nums2[j]) {
                ans[k++]=nums1[i];
                i++;
            }else{
                ans[k++]=nums2[j];
                j++;               
            }
        }
        
        while(i<m) {
            ans[k++] = nums1[i++];
        }
        
        while(j<n) {
            ans[k++] = nums2[j++];
        }
        
        for(int i=0; i<m+n; i++)
        nums1[i] = ans[i];
        
    }
};
