// 别人算法一样，backtracking
// similar with 40.
// 增加一个level参数，必须到0层才压入结果

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<int> candidates{1,2,3,4,5,6,7,8,9};
     vector<vector<int>> result;
     vector<int> cur;
     helper(candidates, n, cur, result, 0, k); 
     return result;
    }
    
private:
    void helper(vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>& result, int pos, int level) { //Note add level
        if(target==0&&level==0){  // Note change 2
            result.push_back(cur);
            return;
        }
        
        if(level<0) // Note change 3
        return;
        
        for(int i=pos; i<candidates.size()&&candidates[i]<=target; i++){ 
            /*if(i!=pos&&candidates[i]==candidates[i-1])  
            continue;*/
            
            cur.push_back(candidates[i]);
            helper(candidates, target-candidates[i], cur, result, i+1, level-1); //Note change 4
            cur.pop_back();
        }
        
    }
    
};
