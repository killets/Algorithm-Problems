//非常好的一道题！division方法中传入parent_sum的做法就像是vector不断push_back的过程。dfs那个方法本质是backtracking。
// for pathsum, path root->leaf ,there are two methods: one is DFS(兼具backtracking),another is division.
//和我们算数字组合的值一样，压入新的+旧的乘以10

//[geek] http://www.geeksforgeeks.org/sum-numbers-formed-root-leaf-paths/
The idea is to do a preorder traversal of the tree. 
In the preorder traversal, keep track of the value calculated till the current node, let this value be val. 
For every node, we update the val as val*10 plus node’s data.


// 3 别人算法 https://leetcode.com/discuss/1711/can-you-improve-this-algorithm [ok]
// 2 Use recursive method, division. [wa]
// 1 Use DFS, int& cursum as a stack, sum as ans; don't forget to pop at leaf nodes. [ok]
//   or you can just don't write two lines above. it calls no sub function, that means return;
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
private:
int sumNumbers(TreeNode* root, int parent_sum){
        int cur_sum = 10*parent_sum+root->val;
        if(root->left == nullptr && root->right == nullptr)
            return cur_sum;
        int sum=0;
        if(root->left){int left = sumNumbers(root->left, cur_sum); sum+= left; }
        if(root->right){int right = sumNumbers(root->right,cur_sum); sum+= right;} 
        return sum;
}
    
public:
    int sumNumbers(TreeNode* root) {
           if(root==nullptr) return 0;
           return sumNumbers(root, 0);
    }
};
 
//2 
/*
class Solution {
private:
    int digit(int number){
        int digits = 1; do { number /= 10; digits*=10; } while (number != 0);
        return digits;
    }
    
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr)
            return root->val;
        int sum=0;
        if(root->left){int left = sumNumbers(root->left); sum= sum + left + root->val* digit(left); }
        if(root->right){int right = sumNumbers(root->right); sum= sum +right + root->val* digit(right);} 
        return sum;
    }
}; */
 
//1
/*
class Solution {
private:
    void DFS(TreeNode* root, int & sum, int & cursum){
        if(root==nullptr) return;
        int copycursum = cursum;
        cursum= cursum*10 + root->val; //push
        if(root->left==nullptr&& root->right == nullptr){
            sum+=cursum; //ans
            cursum=copycursum; //pop  Note!!!
            return;
            //or you can just don't write two lines above. it calls no sub function, that means return;
        }
        if(root->left) DFS(root->left, sum, cursum);
        if(root->right) DFS(root->right, sum, cursum);
        cursum = copycursum;  //pop
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int cursum=0;
        DFS(root,sum,cursum);
        return sum;
    }
};
*/
