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

//update: https://drive.google.com/open?id=0B0BJAgFiD4jIbDlab3JhTVhjVW8
//update: 总结
//方法1，同上，我的第一种写法，先建好空树，然后按照inordr visit的同时设置节点的值；
//方法2，我的第二种写法，安装inorder，左边cnt/2, 中间一个根，右边cnt-cnt/2-1来建树
//update: use recursive inorder build tree
class Solution3 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        int pos=0;
        return helper(nums, pos, nums.size());
    }
private:
    TreeNode* helper(vector<int>& nums, int pos, int cnt){//pos实际上是起始位置
        if(cnt<=0) return nullptr;
        TreeNode * left = helper(nums, pos, cnt/2);
        //pos++;
        TreeNode * root = new TreeNode(nums[pos+cnt/2]);
        //pos++;
        TreeNode * right = helper(nums, pos+cnt/2+1, cnt-cnt/2-1);
        //pos++;
        root->left = left;
        root->right = right;
        return root;
    }
}; 
//写pos++,这样reference的时候没通过

//方法3，第三种写法，也是各种参考答案推荐的写法，取中间celing作为root，然后左半边作为子树，右半边作为右子树
//update: use recursive inorder build tree
 //a. take middle as root
 //b. left is a subtree
 //c. right is right subtree
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        int start=0;
        int end=nums.size()-1;
        return helper(nums, start, end);
    }
private:
    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;
        int mid = start+(end-start+1)/2; //这里要加1，保证是取celing，而不是floor；这样左树比右树相等或多1
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid-1);
        root->right = helper(nums, mid+1, end);
        return root;
    }
}; 
//也可以写成函数调用自己，但这样要新建临时vector作为左输入和右输入；本质和上面相同
