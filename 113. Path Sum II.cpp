//别人算法：这是一道典型的backtracking，【*第一次遇到tree中叫这个】
//我的算法是基于112的recursive解法，记录路径。vectror<vetor<int>>&，然而当前路径没用reference，别人说这样空间太多

This is the backtracking point. If we execute two sub recursive code in else branch and still can't get a match pathSum,
this means the current "root" which already added into the List currentResult can not lead us to the correct answer. 
So we need to remove it from List currentResult and try other possible branches, this is what backtracking means

//我的改动是不多引入下一级，为空就不朝下传
// backtracking
 class Solution {
    public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>> result;
        vector<int> cur;
        helper(root, result, cur, sum);
        return result;
    }
    private:
    void helper(TreeNode* root, vector<vector<int>>&result, vector<int>&cur, int sum){
        //if(root==nullptr) return;
        cur.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&sum==root->val){
            result.push_back(cur);
            cur.pop_back(); // Note!
            return;
        }
        if(root->left) helper(root->left, result, cur, sum-root->val);
        if(root->right) helper(root->right, result, cur, sum-root->val);
        cur.pop_back();
    }
 };
