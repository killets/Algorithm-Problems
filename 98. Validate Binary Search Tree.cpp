// 别人算法是类似我的第一个想法，但是别人实现了，而且还很简洁，left时用个判断，然后right时直接用return；
// 值得学习研究。TODO
// 我的算法是中序遍历，得到一个序列，assert序列是否有序，考虑到遍历时单个树可能判断出已经违背BST，于是设置flag位早点退出。

// runtime error when [], need cast size()-1 to int
// try inorder travel, then assert if it's sorted
// wrong answer [10,5,15,null,null,6,20], since 6 is less than 10  => this method is kind of mess, give up
// recursive way to check, note: no equal allowed [1,1]

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
    bool isValidBST(TreeNode* root) {
    vector<int> nodes;
    helper(nodes, root);
    if(terminate_flag) // if quit early, no need to process all travel
    return false;
    for(int i=0; i< int(nodes.size()-1); i++){ // assert nodes is sorted // runtime error when []
        if(nodes[i]>=nodes[i+1])
        return false;
        
    }
    return true;
    }
private:
    bool terminate_flag = false;
    // in-order travel
    void helper(vector<int>& nodes, TreeNode* root) {
        if(terminate_flag||root==nullptr)
        return;
        
        if(root->left){
            if(root->left->val>=root->val)//if quit early, no need to process all travel
            terminate_flag=true;
            else
            helper(nodes, root->left);
        }
        nodes.push_back(root->val);
        
        if(root->right){
            if(root->right->val<=root->val)//if quit early, no need to process all travel
            terminate_flag=true;
            else
            helper(nodes, root->right);
        }
    }
 }; 
 
 /*
 //give up
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
        return true;
        
        if((root->left &&  root->left->val >= root->val) ||(root->right  && root->right->val <= root->val))
        return false;
        else
        return isValidBST(root->left)&isValidBST(root->right);
    }
    
    bool helper(TreeNode * root, bool lefttree, int upper){
        if(root==nullptr)
        return true;
        
        if(lefttree){
            
            if((root->left &&  root->left->val >= root->val) ||(root->right  && ((root->right->val <= root->val)||(root->right->val >= upper))))
            return false;
            else
            return isValidBST(root->left, true, root->val)&isValidBST(root->right, false, root->val);
        } else{
             if((root->left &&  (root->left->val >= root->val || (root->left->val <= upper))) ||(root->right  && root->right->val <= root->val))
            return false;
            else
            return isValidBST(root->left, true, root->val)&isValidBST(root->right, false, root->val);
            
            
        }
        
        
        
        
    }
    
};
