//别人算法非常精简，思想就是2pointers,把一堆东西分三份，0和2朝两边放，中间剩下1，最有有序。
//我的想法是分三份，然后归类，然后连起来.
//下面的算法是最早写的，思路有点忘了

class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto lt=nums.begin();
        auto i=lt;
        auto gt=nums.end()-1;
        
        int pivot=1;
        while(*i!=pivot&&i!=nums.end()){ // find the pivot
            i++;
        }
        
        if(i==nums.end()){ // if not found, try pivot =0
        
            pivot =0;
            i =nums.begin();
            while(*i!=pivot&&i!=nums.end()){ // find the pivot
            i++;
            }
            if(i==nums.end())
            return;
        }
        
        std::iter_swap(nums.begin(),i);
        i=nums.begin(); 
        
        while(i<=gt){
            if(*i==pivot)
            i++;
            else if(*i>pivot){
                std::iter_swap(i,gt);
                gt--;
            }
            else{
                std::iter_swap(lt,i);
                i++;
                lt++;
            }
        }
        
    }
};
