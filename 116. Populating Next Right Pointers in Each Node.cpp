//别人算法非常巧妙，待理解
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //有点像level遍历，BFS
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        
        int CNT = 1;    
        int cnt = 0;
        TreeLinkNode * old=root;
        TreeLinkNode * tmp;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            cnt++;
            if(cnt==CNT){
                old->next = tmp;
                tmp->next = nullptr;
                CNT = 2*CNT;
                cnt = 0;
                old = tmp;
            } else if(cnt==1){
                old = tmp;
            } else{
                old->next = tmp;
                old = tmp;
            }
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        
        old->next = nullptr;

    }
};
