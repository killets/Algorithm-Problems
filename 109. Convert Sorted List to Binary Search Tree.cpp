/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //别人算法思路本质跟我一样，区别在于我是每步都分开，他是把新建和赋值合成在一起了
 //: [1,2,3,4,5]时我输出[4,2,5,1,3]，答案输出[3,2,5,1,null,4]，还是AC
 //inorder,DFS
 //first,build a false tree, then set value by inorder vist
 //how to build a tree?
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* p = head;
        vector<int> vals;
        while(p) {
            vals.push_back(p->val);
            p=p->next;
        }
        
        int n = vals.size();
        TreeNode* root = buildTree(n);
        int cnt=0;
        inordervisit(root, vals, cnt);
        return root;
    }
private:
    TreeNode* buildTree(int n){
        TreeNode** root = new TreeNode*[n];
        for (int i = 0; i != n; ++i){
            root[i] = new TreeNode(0);
        }
        
        for(int i=0; i<n/2; i++){
            if(2*i+1<n) root[i]->left = root[2*i+1];
            if(2*i+2<n) root[i]->right = root[2*i+2];
        }
        return root[0];
    }
    
    void inordervisit(TreeNode* root, vector<int>& vals, int& n){
        if(root->left) inordervisit(root->left, vals, n);
        root->val = vals[n];
        n++;
        if(root->right) inordervisit(root->right, vals, n);
    }
};
