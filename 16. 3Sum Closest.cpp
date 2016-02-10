//别人算法思路是一样的，讨论中有人指出可以做到我想的那种提前break，实际上是比计较相邻的solution的变化趋势，
// 如果结果开始变坏，那再移动都会继续更坏。比较的是相邻两个的变化，而不是我想到的一个值和当前的min比。

//加上跳过重复元素
//看了3sum的参考答案后修改成two pointers,而不是2个或3个for循环

// 也有三层break; 因为朝右边移动时，假设找到了min，然后移动一位发现比min大，再朝右怕差距会越来越大
// 我的想法是backtracking做的话，就维护一个closet，提前退出条件是差距比上一个closet大，但这样好像只有第三层可以提前退，前两层貌似
// 不退
//计划：1 bk 2 iterative way

class Solution {
public:
     int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int min = INT_MAX;
        int sum = 0;
        
        for(int i=0; i<n-2; i++){
            int front = i+1;
            int back = n-1;
            
            while(front<back){
                int sum3 = nums[i]+nums[front]+nums[back];
               
                if(sum3<target){
                    front++;
                    if(target-sum3< min){
                    min = target-sum3;
                    sum = sum3;
                    }
                    
                    while(front<back&&nums[front]==nums[front-1])
                    front++;
                    
                    
                } else if(sum3==target){
                    return target;
                } else{
                    back--;
                    if(sum3-target< min){
                    min = sum3-target;
                    sum = sum3;
                    }
                    while(front<back&&nums[back]==nums[back+1])
                    back--;                 
                }
            }
            
            while(i+1<n&&nums[i+1]==nums[i])
            i++;
            
        }
        
        return sum;
    } 
 
   int threeSumClosestold(vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int min = INT_MAX;
        int sum = 0;
        
        for(int i=0; i<n-2; i++){
                //  if(abs(nums[i]+nums[i+1]+nums[i+2]-target)>min && nums[i+1]*nums[n-1]>0) //#1
                //      break;
            for(int j=i+1; j<n-1;j++){
                // int t = nums[i]+nums[j]+nums[j+1];
                //   if(abs(t -target) > min &&  t*target>0)//#1
                //       break;
                    
                for(int k=j+1; k<n; k++){
                    int tmp = nums[i]+nums[j]+nums[k];
                    if(abs(tmp-target) < min){
                        min = abs(tmp-target);
                        sum = tmp;
                    } else{
                        //if(tmp*target>0) //#1
                         break;
                    }
                }
            }
        }
        
        return sum;
    } 
    

};
