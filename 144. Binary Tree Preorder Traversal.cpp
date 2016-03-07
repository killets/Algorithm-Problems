/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //别人算法有和我一样的，然后第一名的算法是只保存右子进栈
 
 //1st算法引入了很多不必要的nullptr
 class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return vector<int>();
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        while(!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            
            ans.push_back(tmp->val);
            if(tmp->right) s.push(tmp->right);
            if(tmp->left) s.push(tmp->left); //left first
        }
        return ans;
    }
};
 
 
 //DFS: STACK
 
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        while(!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            if(tmp!=nullptr){
                ans.push_back(tmp->val);
                s.push(tmp->right);
                s.push(tmp->left); //left first
            } 
        }
        return ans;
    }
};
