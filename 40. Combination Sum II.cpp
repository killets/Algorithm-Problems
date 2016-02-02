// 本题在39的基础上做还是很简单的，新增要求即只能用1次；
// 那么首先sub问题中的candidates就不能包括当前的元素，因此要右移一位；
// #其次，因为有重复candidates,那么最外循环中就要避免重复检查已经检查过的方案，比如【1，1,7】找8
// 用两种方法解：recursive or backtracking

// #中，也可以放在pop之后，直接用while句skip掉重复的元素，感觉这样比在for开头检查更易懂

// backtracking way
class Solution {
public:
    // DELET HELPER, USE SINGLE FUNCTION
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> cur;
        helper(candidates, target, cur, result, 0);
        
        return result;
    }
private:
    void helper(vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>& result, int pos) {
        if(target==0){
            result.push_back(cur);
            return;
        }
        
        for(int i=pos; i<candidates.size()&&candidates[i]<=target; i++){ //Note 3:time limmit fix
            if(i!=pos&&candidates[i]==candidates[i-1])  //Note! change 1
            continue;
            
            cur.push_back(candidates[i]);
            helper(candidates, target-candidates[i], cur, result, i+1); //Note! change 2
            cur.pop_back();
        }
        
    }
};

//----------------------------------------
// recursive way
// basic idea is same with 39. sum 1 problem
// changes include 1): newv candidate begin()+ i vs. i+1, see Note #4
// 2)：skip already checked element, see Note #5

class Solution {
public:
    // DELET HELPER, USE SINGLE FUNCTION
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
    
        int n=candidates.size();
        for(int i=0; i<n; i++) {
            if(i!=0&&candidates[i]==candidates[i-1]) //Note #5 1,1,7 find 8, will output 1,7 and 1,7
                continue; // skip
                
             if(candidates[i]==target) {
                 vector<int> cur={candidates[i]}; //take out one element
                 result.push_back(cur);
                 //return result;
             } else if(candidates[i]<target){ 
                if (target-candidates[i] >= candidates[i]){//Note #1, speed up as above Note，never find a smaller number
                 vector<int>::iterator a = candidates.begin()+i+1; //Note #4: every element can use one time, and "no" duplicates
                 vector<int>::iterator b = candidates.end();
                 vector<int> newv(a,b);
                  //helper(newv, target-candidates[i],cur,result);   //Note #2, Important change
                 vector<vector<int>> sub = combinationSum2(newv,target-candidates[i]);
                 if(!sub.empty()){ // if sub problem has solution
                     for(auto & e: sub){ // put "cur+sub" into result
                         vector<int> AB(1+e.size()); //Note #3
                         AB[0]= candidates[i];
                         for(int i=0; i<e.size();i++)
                            AB[i+1]=e[i];
                            
                         result.push_back(AB);
                     }
                 }
                }
             }else
                break;
        }
        
        return result;
    }
};
