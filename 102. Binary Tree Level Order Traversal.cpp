//别人算法第一名是用queue，然而备注中那个是用的pretravle,有点奇怪。

//：Time Limit Exceeded 
//BFS
//按照每层2^n来读，并把各自子节点存入queue中，当某一层全为null时向量为空，依此退出
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //if(root==nullptr) return vector<vector<int>>(); // CAN BE CANCELLED
        vector<vector<int>> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        int cnt =1;
        while(!Q.empty()){
            vector<int> level;
            int newcnt = cnt;
            for(int i=0; i<cnt; i++){
                TreeNode * tmp = Q.front();
                Q.pop();
                if(tmp!=nullptr){
                    level.push_back(tmp->val);
                    Q.push(tmp->left);
                    Q.push(tmp->right);
                }else{
                    //Q.push(nullptr);
                    //Q.push(nullptr);
                    newcnt--; //NOTE: HERE IS THE CHANGE
                }
            }
            
            if(level.empty())
                break;
            else{
                ans.push_back(level);
                cnt = 2*newcnt; //NOTE: CHANGE FROM CNT = 2*CNT
            }
        }
        
        return ans;
    }
};
