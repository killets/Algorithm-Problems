//别人算法确实很简单，stack就是用来记录当前的访问路径，按照中序访问顺序把访问路径压入栈，
//当左树到底了，pop出来，并且开始访问pop出来的那个的右支，又开始压，然后回退，直到回到主干上来
//思路图 https://drive.google.com/open?id=0B0BJAgFiD4jIXzl0MlVtdjE1bHM

// 此题花了2个多小时，指针试来试去
// AC的答案是试出来的，
// 思路是用stack来做iterative, stack记录路径，增加一个变量表示这个是否访问过其子节点，以区分第一次访问还是（中序的父节点从左树返回）
// 访问过则表示左子树已经遍历完了，打印即可
// 未访问过，则先看看有没左树，无则打印，且如果无左树但有右树，则先pop出来当前节点，然后把右树压进去，再把当前节点压回来，
//                                    这样先pop后push，是为了维持inorder的顺序，使当前节点(父)在stack上面，右子在父的下面；
//                                    并且这个过程中把当前节点的visited状态设置为访问过；这样以后，遍历完左树回来时，该节点已访问过，
//                                    就不用再看其子节点了，直接打印即可。
//                    有则，把左树压进去

// Iterative way
// test case [1,2,3] [1,2,3,null,null,4,null,null,5]
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
    struct Node;
    struct Node {
        TreeNode* tree;
        bool visited;
        Node(TreeNode* t): tree(t),visited(false){};
    };
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return vector<int>();
        vector<int> result;
        
        stack<Node> s;
        s.push(Node(root));
        
        while(!s.empty()){
            Node p = s.top(); // 不能定义为引用，否则后面push(p)时值变了
            TreeNode * pp = p.tree;
            
            if(p.visited){
                s.pop();
                result.push_back(pp->val);
                continue;
            }
            
            s.top().visited = true; //考!!!!写成了==true; 一直timelimmited，一个小时
            
            if(pp->left==nullptr) {
                s.pop();
                result.push_back(pp->val);
                if(pp->right){
                    s.push(Node(pp->right));
                }
            } else {
                if(pp->right) {
                    s.pop();
                    s.push(Node(pp->right));
                    p.visited = true;
                    s.push(p);
                }  
                s.push(Node(pp->left));
            }    
        }
        
        return result;
    }
};

//------------------------------------------------------------
// Recursive way
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return vector<int>();
        
        vector<int> result;
        if(root->left) {
            for(auto e: inorderTraversal(root->left))
            result.push_back(e);
        }
        result.push_back(root->val);
       if(root->right) {
            for(auto e: inorderTraversal(root->right))
            result.push_back(e);
        }
        return result;
    }
};
