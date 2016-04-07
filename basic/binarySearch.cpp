二分搜索时，lo和hi的缩进，要不要+-1的问题，有时候会死循环，比如69题。

//出现的错误：
while(lo<hi) 如果只有一个元素时进不去循环

二分搜索的应用：
35题是基础的怎样custom二分搜索，应用到具体问题；
          while(lo<hi){    
            int mid = lo +(hi-lo)/2;
            if(nums[mid]>target){
                hi = mid-1;
            } else if(nums[mid]==target){
                return mid;
            } else {
                lo = mid+1;
            }
        }
        
        return nums[lo]<target? lo+1: lo;
        
      可以融合为while(l0<=hi)
      这要求while内部，lo和hi均必须移动，不能=mid, 否则会无限循环
      
      等同于
              while(lo<hi){    
            int mid = lo +(hi-lo)/2;
            if(nums[mid]>target){
                hi = mid; //NOTE!
            } else if(nums[mid]==target){
                return mid;
            } else {
                lo = mid+1;
            }
        }
        
        return lo;
        
        2）如果有重复元素，则要找开头第一个，不能直接return
        int low = 0, high = nums.size()-1;
        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
        
       也等同于
        int lo=0;
        int hi=nums.size()-1;

        while(lo<hi){    
            int mid = lo +(hi-lo)/2;
            if(nums[mid]<target){
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return nums[lo]<target?lo+1:lo;  // [1] find 2

34题则更进一步，如何找数的两个边界

?题使用binary search找局部最大值
