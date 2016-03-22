//别人算法非常巧妙，待理解
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //update：我写的BFS方法中用到cnt来记数，但cnt到2^n时认为到头了
 //在学了while中套for的level order traversal之后，可以这样做：
 
 //注意这样错了。因为stack的一层还没读完就被新的节点抢先了，还是要用queue
 void connect(TreeLinkNode* root) {
   if(root==nullptr) return;
   stack<TreeLinkNode*>s;
   s.push(root);
   
   while(!s.empty()){
    int n= s.size();
    TreeLinkNode* pre = nullptr;
    for(int i=0; i<n; i++) {
     TreeLinkNode* tmp = s.top(); s.pop();
     tmp->next = pre;
     pre= tmp;
     if(tmp->left) s.push(tmp->left);
     if(tmp->right) s.push(tmp->right);
    }
   }
  
 }
 

 void connect(TreeLinkNode* root) {
   if(root==nullptr) return;
   queue<TreeLinkNode*>q;
   q.push(root);
   
   while(!q.empty()){
    int n= q.size();
    TreeLinkNode* pre = nullptr;
    for(int i=0; i<n; i++) {
     TreeLinkNode* tmp = q.front(); q.pop();
     if(pre) //NOTE!
        pre->next = tmp;
     pre= tmp;
     if(tmp->left) q.push(tmp->left);
     if(tmp->right) q.push(tmp->right);
    }
   }
 }

 
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
