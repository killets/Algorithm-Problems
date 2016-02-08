//别人算法，首先DFS，树的depth就是左树，右树的最大，+1，而当为空时为0
//BFS的算法，和我的相似，不过用的是queue
//我的实际上是DFS的iterative实现

//我的思路是到了分叉处就压入当前深度和分叉到stack里面，继续当前路径，直到底，然后回来
// stack继续，直到stack为空

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
    struct node{
        TreeNode* p;
        int cnt;
        node(TreeNode* p, int cnt):p(p),cnt(cnt){}
    };

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<node> s;
        s.push(node(root, 1));
        int max = 1;
        while(!s.empty()){
            node cur = s.top();
            s.pop();
            if(cur.p->right){
            s.push(node(cur.p->right, cur.cnt+1));
                if(cur.cnt+1>max) max = cur.cnt+1;
            }
            if(cur.p->left){
            s.push(node(cur.p->left, cur.cnt+1)); 
                if(cur.cnt+1>max) max = cur.cnt+1;
            }  
        }
        return max;
    }
    
};
