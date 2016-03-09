/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //我的算法还是和109一致，分步建树设值，别人算法合在一起
 //same as 109, bst is equal to inorder
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
     if(nums.size()==0) return nullptr;
     TreeNode* root = buildTree(nums.size());
     int pos = 0;
     inorderVisit(root, nums, pos);
     return root;
    }
    
private:
    TreeNode* buildTree(int n){
        TreeNode** tree = new TreeNode*[n];
        for(int i=0; i<n; i++){
            tree[i] = new TreeNode(0);
        }
        
        for(int i=0; i<n/2; i++){
            if(i*2+1<n) tree[i]->left = tree[i*2+1];
            if(i*2+2<n) tree[i]->right = tree[i*2+2];
        }
        return tree[0];
    }
    
    void inorderVisit(TreeNode* root, vector<int>& nums, int& pos){
        if(root->left) inorderVisit(root->left, nums, pos);
        root->val = nums[pos];
        pos++;
        if(root->right) inorderVisit(root->right, nums, pos);
    }    
    
};
