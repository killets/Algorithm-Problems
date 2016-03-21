//别人算法是利用递归，为左右子树的min+1，但是当左右树有一个为空时，为另一个+1
//我的按层遍历BFS的算法要比别人的好，因为别人不管怎样都要遍历所有的节点，而BFS可以提前退出；
//这一点也可以从geek上得证：http://www.geeksforgeeks.org/find-minimum-depth-of-a-binary-tree/

 //update: 学完level Order Trversal后想到这个方法，应该是BFS是最优的；o(n)
 //当第一次遇到一个节点为leaf节点时即停止
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int cnt =1;
        while(!q.empty()) {
            int n= q.size();
            for(int i=0; i<n; i++) {
                TreeNode* tmp = q.front(); q.pop();
                if(tmp->left==nullptr && tmp->right==nullptr)
                    return cnt;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            cnt++;
        }
    }
}; 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_OLD {
private:
    int min=INT_MAX;
public:
    int minDepth(TreeNode* root) {
        helperDFS(root, 0);
        return min==INT_MAX? 0 : min;
    }
    
    void helperDFS(TreeNode* p, int cnt) {
        /*  Note: if not add below conditions, for [5,4,7,3,null,2,null,-1,null,9], 
                the null one will give wrong depth */
                
        // if it's not empty and not leaf node
        if(p!=nullptr && (p->left!=nullptr||p->right!=nullptr) ) {
            cnt++;
            if(cnt>=min)
            return;
            helperDFS(p->left, cnt);
            helperDFS(p->right, cnt);
        } // only if it's a leaf node then stop and update min
        else if(p!=nullptr && p->left ==nullptr && p->right ==nullptr) {
            cnt++;
            if(cnt<min)
            min = cnt;
            return;
        }
    }
};
