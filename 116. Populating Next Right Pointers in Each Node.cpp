//别人算法非常巧妙，待理解【已经理解了，就是按层访问，然后设置各层的子节点间的link关系；两层循环】

void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre; //一层的开头，设置这一层的子节点间的link连接
        while(cur) {
            cur->left->next = cur->right; //当前节点左子的next=当前的右子
            if(cur->next) cur->right->next = cur->next->left;//右子的next,等于当前的next的left，如果存在的话
            cur = cur->next;//当前右移一位
        }
        pre = pre->left;  //进入下一层
    }
}

//等价于：

//题目有要求constant space，所以不用queue 
//很大的一个假设是有两个孩子，perfect bT, 所以这里直接left;如果没有这个假设，那么需要判断两个问题
//第一，while outer->left 要改，第二，inner->right->next = inner->next->left要改
class Solution {
public:
    void connect(TreeLinkNode* root) {
        if(root==nullptr) return;
        TreeLinkNode* outter = root;
        TreeLinkNode* inner = nullptr;
        
        while(outter->left){//下一层有节点才能设
            inner = outter;
            while(inner) {
                inner->left->next = inner->right; //left存在
                if(inner->next) inner->right->next = inner->next->left; //很大的一个假设是有两个孩子，所以这里直接left
                inner = inner->next; //如果没有这个假设，
            }
            outter = outter->left;
        }
    }
};

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
