/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //别人提到需要用dp，因为重复子问题计算了很多次，可以直接复用，但复用时，要clone那个子树，不然节点会被share。
 //anw，recursive方法以及足够，比较简洁
 
 //自己想出来的，与最高票不谋而合
 //方法1：DP，在96的基础上，存结构，然后拼成新的结构，（设置结构的基点），返回根
 //方法2：recursive，调用自己，选择根之后，是两个子问题
 //比较之下方法2更合适
 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        return generateTreesHelper(1, n);
    }
private:    
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        if(start>end) return vector<TreeNode*>{nullptr};
        if(start==end) return vector<TreeNode*> {new TreeNode(start)}; //避免再进入loop去调用下一级
        
        vector<TreeNode*> ans;
        for(int i=start; i>0 && i<=end; i++){//等于end等号还是要的，因为root要取到end的值
            vector<TreeNode*> left = generateTreesHelper(start, i-1);
            vector<TreeNode*> right = generateTreesHelper(i+1, end);
            for(auto & l: left)
            for(auto & r: right){
                TreeNode* root = new TreeNode(i); //Note：evey time crate a new root, otherwise overwirte the same root every loop, 
                                                // you only get 1 root
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
        return ans;
    }
};
