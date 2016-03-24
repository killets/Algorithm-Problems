//有两种算法，recursive如下
//iterative,用两个指针和栈去做dfs遍历（比较简单的是做preorder或inorder），要有相同的path和data才相同
//另外类似问题same bst : http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/

//1 divide and concur method;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p!=nullptr && q!=nullptr && p->val==q->val)
        return isSameTree(p->left,q->left)&isSameTree(p->right, q->right);
        return false;
    }
};
