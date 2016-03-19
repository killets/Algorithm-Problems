//udpate 自己总结见后
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

//------------------------------------------------------------------------------------------------------
//更新：以下是我的总结
//这题也是有两大类方法，iterative比recursive好懂，

//这个是我的第一次尝试，也通过了，方法是按照树的个数，2^n来遍历一层，空的也算数
class Solution2 {
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

//B: 然后这个是经典的while加for的做法，和我A的思路是一致的，不过更加巧妙，每次都pop出原来所有的，然后
//新添加他们的第一代子女进去，下次进while的for就是遍历所有这些新加的节点。避免了2ton的记数。
//update: while()里面for，for的个数为之前queue的size
class Solution3 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            vector<int> alevel;
            int n=Q.size();
            for(int i=0; i<n; i++) {
                TreeNode* tmp = Q.front(); Q.pop();
                alevel.push_back(tmp->val);
                if(tmp->left) Q.push(tmp->left);
                if(tmp->right) Q.push(tmp->right);
            }
            result.push_back(alevel);
        }
        return result;
    }
};

//C: RECURSIVE的方法也很奇妙，思路就是使用PRE-ORDER这样来，将遍历到的节点都插入到result中去，因此
//父节点传下去depth+1,根据depth就知道该放入哪个里面，（pre-order虽然是DFS，depth不连续，但depth是传的是值保证了层不错（层对号入座），然后
//pre-order这个也保证了一层中先左后右的顺序没有乱；如果是先right再left，那就乱了）
//然后插入的层怎么新增呢？如果depth从0开始，则以result.size()==depth为标准，第一个新建层向量；
//如果以depth=1开始，那么则以result.size()<depth为标准新建向量。注意插入值则要设置result[depth-1]

//update: recursive 方法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>> result;
        build(root, result, 1); //这里root是第一层
        return result;
    }
private:
    void build(TreeNode* node, vector<vector<int>>& result, int depth){
        if(node==nullptr) return;
        
        if(result.size()<depth){ //那么这里就要变成<
            result.push_back(vector<int>());
        }
        
        result[depth-1].push_back(node->val); //这里要变-1
        build(node->left, result, depth+1);
        build(node->right, result, depth+1);
    }
}; 

//等价的假如传入的depth从1开始，
//update: recursive 方法
class Solution_equal {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>> result;
        build(root, result, 0);
        return result;
    }
private:
    void build(TreeNode* node, vector<vector<int>>& result, int depth){
        if(node==nullptr) return;
        
        if(result.size()==depth){
            result.push_back(vector<int>());
        }
        
        result[depth].push_back(node->val);
        build(node->left, result, depth+1);
        build(node->right, result, depth+1);
    }
};
