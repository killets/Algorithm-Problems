//值得研究 TODO
//别人算法好在固定一个动两个，前面是O(N)，后面也是O(n),总O(N^2);我开始时三个for那个肯定慢O(N^3)，后来改的定前面两个，for，里面第三层用
//hash表，虽然是O(N^2),但还不是最快的。 别人算法里面有个特征是，当sum《target时，右移动front，》时，左移动back。这个在哪见过，要搞清楚。TODO
//衍生：2sum时naive是o（n^2）, 它这个是O(n)

// 改为别人的算法，固定第一个，移动后两个，注意去重复时的跳法，结果：速度在最前面的长柱子
// 别人算法并没有加这些提前退出反倒快，我觉得可能是test case问题，来试试别人的去掉break，结果：更慢
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            int front = i+1;
            int back = n-1;
            
            while(front<back) {
                //cout<<nums[i]<<nums[front]<<nums[back]<<" :"<<i<<" "<<front<<" "<<back<<endl;
                
                int sum3 = nums[i]+nums[front]+nums[back];
                if(sum3<0) {
                    front++;
                    while( front<back && nums[front]==nums[front-1]) //移动front，那就只跳front
                    front++;                    
                } else if(sum3==0){
                    result.push_back(vector<int>{nums[i],nums[front],nums[back]});
                    front++;
                    back--;
                    while( front<back && nums[front]==nums[front-1]) //都跳
                    front++;
                
                    while(back>front && nums[back]==nums[back+1])
                    back--;
                    
                } else{
                    back--;
                    while(back>front && nums[back]==nums[back+1]) //只跳back
                    back--;                    
                }

            }

            while((i+1)<(n-2)&&nums[i+1]==nums[i]) //只跳i
            i++;
        }
        
        return result;
    }

};


// 第三层的break想到了但没写出来起作用，继续加，反倒变慢了
// 增加第一个数>0的判断，for的n继续缩小 =》快了20%+，前面还有20%
// 第三个数直接用hash表来做，不用for了

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        unordered_map<int, int> hmap;
        for(auto e: nums)
        hmap[e]=1;
        
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(nums[i]>0) break; //一直漏了这一条，sum1
            for(int j=i+1; j<n-1; j++){
                int sum2 = nums[i]+nums[j]; //sum2
                if(sum2>0 || 0-sum2 < nums[j] ) //继续增加, 这是第三层的break; Note 1
                    break;
                if((0-sum2>nums[j] && hmap[0-sum2]==1)||( 0-sum2==nums[j] && j+1<n&&nums[j+1]==nums[j]) ){
                    result.push_back(vector<int>{nums[i],nums[j],0-sum2});
                }
                while(j+1<n&&nums[j+1]==nums[j])
                j++; 
            }
            while(i+1<n&&nums[i+1]==nums[i])
            i++;
        }
        return result;
    }

};


//-----------------------------------------------------------------------------------
// 两层要break j返回到i，三层要break k 返回到j; 另外三层均需要while判断跳过重复

//还是不够快，题目tag提示two pointers,看来是要直接iterate做

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]+nums[j]>0)
                    break;
                for(int k= j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    } else if(nums[i]+nums[j]+nums[k]>0){ //no need to proceed with this i,j, change to different i
                        break; // break to i;
                    }
                    while(k+1<n && nums[k+1]==nums[k])
                    k++;
                }   
                while(j+1<n&&nums[j+1]==nums[j])
                j++; 
            }
            while(i+1<n&&nums[i+1]==nums[i])
            i++;
        }
        return result;
    }

};
//-----------------------------------------------------------------------------------------------------------------------
//继续优化时间，还属于中等偏下，减少栈的调用，即把退出条件放在for里面，而不到下一级的helper

//加入一个sum参量，记录目标数，如果要找sum<0说明前面一个或两个和已经>0了

//首先是基本解法，不带任何优化，然后优化条件是算到目前值已经>0了，那么直接就退出了，不再继续【这个还有点麻烦TODO】
// 并且这里是固定的三个元素，所以完全可以不用vector 【光这已经解决了tl问题】

//这个题要用backtracking

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> cur(3);
        helper(cur, nums, result, 0, 3, 0);
        return result;
    }
    
private:
    void helper(vector<int>& cur, vector<int>& nums, vector<vector<int>>& result, int pos, int cnt, int sum){
        for(int i=pos; i<nums.size();i++){
            cur[3-cnt] = nums[i];
            if(sum-nums[i]<0) //已经不可能了,因为前面的已经加起来是正数了
            return;
            
            if(cnt==1){ 
                if(cur[0]+cur[1]+cur[2]==0){ //退出条件
                    result.push_back(cur);
                }
            } else { 
                helper(cur, nums, result, i+1, cnt-1, sum-nums[i]);
                // if(cur[0]+cur[1]>0)
                // break;
            }
            while( i+1<nums.size()&& nums[i]==nums[i+1]) //跳过重复的
                i++;
        }
    }
};

//----------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> cur;
        helper(cur, nums, result, 0, 3);
        return result;
    }
    
private:
    void helper(vector<int>& cur, vector<int>& nums, vector<vector<int>>& result, int pos, int cnt){
        if(cnt==0){
            int sum = 0;
            if(sum==0){
                result.push_back(cur);
            }
            return;
        }
 
        for(int i=pos; i<nums.size();i++){
            cur.push_back(nums[i]);
            helper(cur, nums, result, i+1, cnt-1);
            cur.pop_back();
            while( i+1<nums.size()&& nums[i]==nums[i+1])
            i++;
        }
    }
