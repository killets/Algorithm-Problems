//代表了一种思想，将需要的移动到某一位置，
// inplace思想
// 注意读题，综合的几种方法具体见comments

// 4 input is sorted, details in comments
// 3 still time limmit exceed, input is sorted(NOTE). so there are
// much easier way to solve this problem
// just count duplicate numbers, then overwrite current item to correct place

// 2 time limmit exceeded, I think the problem is that nums are moved too many unecessary times
// updated idea is to mark duplicate places, then move chunk by chunk
// use first element to mark duplicate
// use processedCnt to locate which place to insert

// 1 my idea is from right most to left most,
// check if it's happend before, if yes, then move its right part to left

#include<iostream>
 #include<string>
 #include<vector>
 
using namespace std;

class Solution {
public:
  // this is 2: improved method, can solve un-sorted array 
   int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        int delcnt=0;
        int dup = nums[0];
        // mark duplicates
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++){
                if(nums[j]==nums[i]){
                    nums[j] = dup;
                    delcnt++;
                    cout<<nums[i]<<"dup"<<endl;
                }
            }
        }
        cout<<delcnt<<"times"<<endl;
        
        for(int i=0; i<n; i++)
        cout<<nums[i]<<" ";
        cout<<"over"<<endl;
        
        // +---+--------++-----+ +is dup
        // re-shape elements
            int processedCnt=0;
            int i=1;
            while(i<n) {
                if(nums[i]==dup) {
                    processedCnt++;
                    int k=i+1;
                    while(k<n&&nums[k]==dup) {
                        k++;
                        processedCnt++;
                    }
                
                    while(k<n&&nums[k]!=dup){
                        nums[k-processedCnt] = nums[k];
                        k++;
                    }
                    i=k;// update i, Note! not k+1
                } else
                    i++;
            }
            
        cout<<processedCnt<<"processedCnt"<<endl;
        for(int i=0; i<n; i++)
        cout<<nums[i]<<" ";
        cout<<"over"<<endl;
        
        return n-processedCnt;
    }
};
int main() {
Solution slu;
vector<int> in ={1,2,3,2,1,5,1,5,6};
cout<<slu.removeDuplicates(in)<<endl;

}
