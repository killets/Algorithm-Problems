//别人算法跟我想的一样，算完后reverse一次，比insert快； 然后它的做法和102题我备注别人的做法一样，递归
// 1变2， 2变4，4变8，伴随创建新level的向量

// 2 nd version: based on 102, push_back + reverse;
// trival version: based on 102, reverse the order: push_back -> insert(ans.begin(),)
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
                //ans.insert(ans.begin(),level); //NOTE CHANGE FOR 107
                ans.push_back(level);
                cnt = 2*newcnt; //NOTE: CHANGE FROM CNT = 2*CNT
            }
        }
        
        std::reverse(ans.begin(), ans.end());
        
        return ans;
        
        
    }
};

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
class Solution_102 {
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
