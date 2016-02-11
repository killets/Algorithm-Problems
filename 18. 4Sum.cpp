//TODO 为什么是相等时else判断去重，这个并没有去掉不等时的重复case判断；我觉得他的目的首先是去掉答案中的重复，并不是以加快为首要目的
//别人rank低一点的那个最快，算法思路也大致相同，用的two pointers,外围用两个for，它的特点在于
//提前退出和去重复写得很简洁，快在这点上。

//别人算法思路是一样的，而且没有那么多提前退出判断；区别在于去重复，它的代码写得简单一些。
//测试发现并不是最快的，只有73%

//继续修改提前退出条件，#3 有效，提升百分之一二十；目前已经是击败86% 但前面还有更快
//继续修改条件为eg. nums[i]>target/4 #2 结果变慢
//在外层加上break，提前退出 #1, 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int n= nums.size();
        for(int i=0; i<n-3; i++) { //#4 n => n-3
        // while(i+4<n && nums[i]==nums[i+4])
        // i++;
        if(nums[i]> (target/4)) //#1 #2
        break;
            
        for(int j=i+1; j<n-2; j++){ //#4
        // while(j+3< n && nums[j]==nums[j+3])
        // j++;
          if(nums[i]+nums[j]> (target/2)) //#1 #2
          break;
          
            int front = j+1;
            int back = n-1;
            
            while(front<back){ //#2
                int sum4= nums[i]+nums[j]+nums[front]+nums[back];
                if(sum4<target){
                    front++;
                    
                    if(nums[i]+nums[j]+nums[back]+nums[back]<target) //#3
                    break;
                    
                    while(front<back && nums[front]==nums[front-1])
                    front++;
                } else if(sum4==target){
                    result.push_back(vector<int>{nums[i],nums[j], nums[front], nums[back]});
                    front++;
                    back--;
                    while(front<back && nums[front]==nums[front-1])
                    front++;
                    while(front<back && nums[back]==nums[back+1])
                    back--;
                } else{
                    back--;
                    if(target - nums[i]-nums[j]-nums[front]<nums[front]) //#3
                    break;
                    while(front<back && nums[back]==nums[back+1])
                    back--;
                }
            }
            
            while(j+1<n && nums[j]==nums[j+1])
            j++;
        }
        
         while(i+1<n && nums[i]==nums[i+1])
         i++;
        }
        
        return result;
    }
};

//内层用hashmap

       for(int k=j+1; k<n && target-nums[i]-nums[j]-nums[k]>=nums[k]; k++){
                if(m.find(target-nums[i]-nums[j]-nums[k])!=m.end() && m.find(target-nums[i]-nums[j]-nums[k])->second >k){
                    result.push_back(vector<int>{nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]});
                }
                while(k+1<n && nums[k]==nums[k+1])
                k++;
            } 


//--------------------特别慢：https://drive.google.com/open?id=0B0BJAgFiD4jIa2QzdmRWdW1fTDA -----------------------
//难点在怎么去重，外两层，内层都去
//利用3sum的two pointers思想,那么固定1，2个数，剩余的3，4作为双指针，o(n^2*n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int n= nums.size();
        for(int i=0; i<n; i++) {
        // while(i+4<n && nums[i]==nums[i+4])
        // i++;
            
        for(int j=i+1; j<n; j++){
        // while(j+3< n && nums[j]==nums[j+3])
        // j++;
        
      
        
            int front = j+1;
            int back = n-1;
            
            while(front<back){
                int sum4= nums[i]+nums[j]+nums[front]+nums[back];
                if(sum4<target){
                    front++;
                    while(front<back && nums[front]==nums[front-1])
                    front++;
                } else if(sum4==target){
                    result.push_back(vector<int>{nums[i],nums[j], nums[front], nums[back]});
                    front++;
                    back--;
                    while(front<back && nums[front]==nums[front-1])
                    front++;
                    while(front<back && nums[back]==nums[back+1])
                    back--;
                } else{
                    back--;
                    while(front<back && nums[back]==nums[back+1])
                    back--;
                }
            }
            
            while(j+1<n && nums[j]==nums[j+1])
            j++;
        }
        
         while(i+1<n && nums[i]==nums[i+1])
         i++;
        }
        
        return result;
    }
};
