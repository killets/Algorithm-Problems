
//我的递归算法很nice!和别人算法一致。
//然后我二刷时，没有回想起来这个recursive的方法，于是想的iterative 的dfs，新建了一个结构体，加入了之前的sum
//这样访问到有分叉时，就将右支和当前和存入stack中，当iterator遍历完了左支，在下一个while中又load原来存好的分叉。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //update: this is not good as my first one, but it works
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum_target) {
      if(root==nullptr) return false;
      
      stack<node> s;
      TreeNode* it= root;
      int sum=0;
      
      while(it||!s.empty()) {
          if(it==nullptr) {
              node tmp = s.top(); s.pop();
              it=tmp.p;
              sum = tmp.sum;
          } else{
              sum+=it->val;
              if(it->left==nullptr && it->right==nullptr) {
                  if(sum_target==sum)
                    return true;
                  else{
                      it=nullptr;
                  }
              } else{
                  if(it->right) s.push(node(it->right, sum));
                  it = it->left;
              }
              
          }
          
      }
    
    return false;
    }
private:
    struct node{
        TreeNode* p;
        int sum;
        node(TreeNode* p, int sum):p(p),sum(sum){}
    };
    
};

//this is cool!
class Solution_OLD {
private:
bool flag = false;
void DFS(TreeNode* root, int sum){
        if(root== nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            if(root->val == sum){
                flag = true;
                return;
            }
        }
        if(root->left) DFS(root->left, sum-root->val);
        if(root->right) DFS(root->right, sum-root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        DFS(root, sum);
        return (flag==true);
    }
};
