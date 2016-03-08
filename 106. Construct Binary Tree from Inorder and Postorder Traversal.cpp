/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //我想别人算法也是一样的吧，这题直接在105的基础上稍作调整即可，自己想出来的!!!
 //图解：https://drive.google.com/open?id=0B0BJAgFiD4jIQ2trdHEtY1FPYkE
 
//先做的105， pre+inorder
//现在这题是,post+inorder
//post倒着读，那么就能保证先读到根，然后才是右子，再才是左子,这样只要调整index--，然后build中的build顺序即可
class Solution{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        std::unordered_map<int, int> m;
        for(int i=0; i<inorder.size(); i++) {
            m.insert(make_pair(inorder[i],i));
        }
        int index = postorder.size()-1;
        return buildTree(postorder, inorder, 0, inorder.size(), index,  m);
    }
    
private:
    //inorder[start, end) 
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int start, int end, int& index, unordered_map<int, int>& m) {
        if(end==start)
        return nullptr;
        
        if(end-start==1) {
            index--; //注意倒着读
            return new TreeNode(inorder[start]);
        }
        
        int rootval = postorder[index];
        //speed up 2
        //int rootpos = partion(inorder, start, end, rootval);
        int rootpos = m[rootval];
        
        /*vector<int> left, right;
        if(rootpos!=0) left = vector<int>(inorder.begin(),inorder.begin()+rootpos);
        if(rootpos!=inorder.size()-1) right = vector<int>(inorder.begin()+rootpos+1,inorder.end());
        */
        TreeNode* root = new TreeNode(rootval);
        index--;
        //注意这里顺序颠倒了，根-右-左
        root->right = buildTree(postorder, inorder, rootpos+1, end, index, m);
        root->left = buildTree(postorder, inorder, start, rootpos, index, m);
        return root;
    }

};
