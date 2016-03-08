//别人的算法都很好，值得学习，待解。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //preorder
 //dfs,原来打印的地方，就把这个数插入到一个新的stack中去，最后这个栈即为dfs的结果，弹出来的都作为新头
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        stack<TreeNode*> s;
        stack<TreeNode*> s2;
        s.push(root);
        while(!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            s2.push(tmp);
            if(tmp->right) s.push(tmp->right);
            if(tmp->left) s.push(tmp->left);
        }
        
        TreeNode * newHead = nullptr;
        while(!s2.empty()){
            TreeNode* tmp = s2.top();
            s2.pop();
            tmp->right = newHead;
            tmp->left = nullptr;
            newHead = tmp;
        } //root is not changed
    }
};
