//tag标签是backtracking，别人算法用到公式递归，（dp思想）；也提到dfs（类似backtrack）
// dp思想即，对于一个数n,要么选中，则在n-1数中选k-1，要么未选中，则在n-1数中选k

// 一个小小的变化，速度相差好远，优化点在于减少不必要的调用，把条件判断放在subhelper之前
//https://drive.google.com/open?id=0B0BJAgFiD4jIWExlN3VIZ1ozdXc

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> com(k);
        helper(result, com, n, k);
        return result;
    }
    
private:
    void helper(vector<vector<int>>& result, vector<int>& com, int max, int k){
        if(k==0){
            result.push_back(com);
            return;
        }
        
        for(int i=max; i>=1;i--){
            if(i < k)  //有要足够多的数，填完剩余的位数 // NOTE 变化，可以减少很多无谓的栈调用
            return;
            com[k-1] = i; //填当前位
            helper(result, com, i-1, k-1);
        }
    }
};



//这个题做的时候感觉可能会慢，因为感觉到可以用iterative方法直接写，而不用recursive复杂
//思路是从最后一位设置起，设置该位为i,那么它前面的都比i小，还剩k-1个数，但剩0个数时把当前组合压入result
//参考答案和我的逻辑刚好相反，从第一位设置起
//有个条件可以用于优化，即最大的位不可能出现在前面，否则后面没数用了。

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> com(k);
        helper(result, com, n, k);
        return result;
    }
    
private:
    void helper(vector<vector<int>>& result, vector<int>& com, int n, int k){
        if(n < k)
        return;
        
        if(k==0){
            result.push_back(com);
            return;
        }
        
        for(int i=n; i>=1;i--){
            com[k-1] = i;
            helper(result, com, i-1, k-1);
        }
    }
};
