/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //参考geek解法2，使用1个stack进行指针操作
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    if(root==nullptr) return vector<int>();
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* cur = root;
    do{
        // down to left-most one
        while(cur){
            if(cur->right)// right, then root, so from stack get root, then right, and can check root->right = stack.nexttop
                s.push(cur->right);
            s.push(cur);
            cur = cur->left; //go to left
        }
        
        cur = s.top(); s.pop();
        // root has a right children, so go to that subtree
        if(cur->right&&!s.empty()&&s.top()==cur->right){ //Undefined behavior, top if empty
            s.pop(); 
            s.push(cur); // push back root, process right subtree first
            cur = cur->right;
        }else{
            result.push_back(cur->val);
            cur = nullptr;// so next cur = s.top()
        }
    }while(!s.empty());
    
    return result;    
    }
};    
 
 
//参考的geekforgeek的思路，使用两个stack，第二个stack的作用是调换左右子（树）的顺序
//与前面构建二叉树中的思路有联系，pre-order根左右，反过来就是右左根，有点像postorder
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return vector<int>();
        vector<int>result;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode * p = s1.top(); s1.pop();
            s2.push(p);
            if(p->left) s1.push(p->left);
            if(p->right) s1.push(p->right);
        }
        
        while(!s2.empty()) {
            TreeNode * p = s2.top(); s2.pop();
            result.push_back(p->val);
        }
        
        return result;
    }
};
