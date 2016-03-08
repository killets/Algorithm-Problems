/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //我开始没思路，参考的http://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
 
 //别人算法思路也是从pre中取数，然后把inorder分左右树，然后再从pre中取数，继续分左树，右树
 //我的实现中很关键一点是，pre中index依次增加，实际上刚好和build合拍，每增加一个index，意味着build中build了一个子root节点，
 //而build中恰好是这种先root，（index+1）， 左（index+1），可能是再左（index+1），然后回来右(index+1),恰好都一一对应上了，
 //即build的实现顺序和preorder中的顺序一致，所以要保证build是preorder.
 
 //这个上升到82
 //speed up 2: partion find use std::unordered_map o(1) instead of o(n)
 
 //这个由8上升到58%
 // not very fast, so speed up:
 // 1.not copy left and rigth vector, pass [start, end)
 //tips from geekforgeek
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int, int> m;
        for(int i=0; i<inorder.size(); i++) {
            m.insert(make_pair(inorder[i],i));
        }
        int index = 0;
        return buildTree(preorder, inorder,0, inorder.size(), index,  m);
    }
    
private:
    //inorder[start, end) 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index, unordered_map<int, int>& m) {
        if(end==start)
        return nullptr;
        
        if(end-start==1){
            index++;
            return new TreeNode(inorder[start]);
        }
        
        int rootval = preorder[index];
        //speed up 2
        //int rootpos = partion(inorder, start, end, rootval);
        int rootpos = m[rootval];
        
        /*vector<int> left, right;
        if(rootpos!=0) left = vector<int>(inorder.begin(),inorder.begin()+rootpos);
        if(rootpos!=inorder.size()-1) right = vector<int>(inorder.begin()+rootpos+1,inorder.end());
        */
        TreeNode* root = new TreeNode(rootval);
        index++;
        root->left = buildTree(preorder, inorder, start, rootpos, index, m);
        root->right = buildTree(preorder, inorder, rootpos+1, end, index, m);
        return root;
    }
    
    int partion(vector<int>& inorder, int start, int end, int val){
       for(int i=start; i<end; ++i) {
           if(inorder[i]==val)
           return i;
       }
    }
};
