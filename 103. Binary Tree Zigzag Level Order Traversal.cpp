/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //别人想法很棒，while中嵌套loop，一进入while，就数一下queue中有多少个元素，这些元素都是同一层的，
 //然后创建新的向量，按照zig-zag模式，做一个for loop（这个size）填充这个向量的各个位置；然后这一批都弹出来了，它们的子节点都
 //进去了；于是下一个while来了，又是处理新的一层。太棒了！！！
 //将树分层！
 //java那个版本是利用recursive传入level这个参数，然后也去判断ans.size（）和现在的level的关系，因此也是只新建1次。
 
 
 //我自己想的，而且是最快的！！！
 //bfs, the chanllenge is when to crate a new vector
 // so i use isPowerOfTwo to do this, need to count empty node, (failed, will never stop)
 
 // Note: i finally get a solution, need not count, but put node's pos index
 // along with its pointer to the queue.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        queue<nodeInfo> q;
        q.push(nodeInfo(root,1));
        vector<vector<int>> ans;
        helper(ans, q);
        return ans;
    }
    
private:
    struct nodeInfo{
        TreeNode* t;
        int index;
        nodeInfo(TreeNode* t, int index):t(t), index(index){}
    };
    
    void helper(vector<vector<int>>& ans, queue<nodeInfo>& q){
        while(!q.empty()){
            TreeNode* tmp = q.front().t;
            int cnt =q.front().index; 
            q.pop();
            
            //if(isPowerOfTwo(cnt)){
            if(cnt>=(1<<ans.size())){
                ans.push_back(vector<int>());
            }

            if(ans.size()%2==0){
                ans[ans.size()-1].insert(ans[ans.size()-1].begin(), tmp->val);
            } else{
                ans[ans.size()-1].push_back(tmp->val);
            }
            
            if(tmp->left) q.push(nodeInfo(tmp->left, 2*cnt));
            if(tmp->right) q.push(nodeInfo(tmp->right, 2*cnt+1));
        }
    }
};

    // bool isPowerOfTwo (int x) {
    //     while (((x & 1) == 0) && x > 1) /* While x is even and > 1 */
    //     x >>= 1;
    //     return (x == 1);
    // }
