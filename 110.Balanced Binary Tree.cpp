//难点算法复杂度计算，http://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
//原始算法的缺陷在于没有将子数的高度传上来，导致重复计算。所以geeksforgeeks中可以看到返回量还是bool，但还带了高度参数
//cc150的算法就直接把返回量bool改成了int，表示高度，但有高度还不行，还要看是否平衡，于是用-1代表了状态量，可谓妙手。
//所以optimized的是cc150的这个，看起来要简洁下，但基于以上分析我们也看到了他们本质上的一致性，都是为了弥补原始算法高度的缺陷
//视频解析：https://drive.google.com/open?id=0B0BJAgFiD4jIQzJPYmN1dXdpRTg

//别人算法来自cc150,注意检查左右子各自是否平衡
//最慢的算法O（nlogn），注意不是o(n^2)
//左树平衡，右树平衡且左右等高或相差1 ,利用104   
    bool isBalanced(TreeNode* root) {
         if(root==nullptr) return true;
        int x = abs(depth(root->left)-depth(root->right));
        return (isBalanced(root->left)&&isBalanced(root->right)&& x<=1);
    }
    
private:
    int depth(TreeNode* root) {
        if(root==nullptr) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }

//错在[1,2,2,3,null,null,3,4,null,null,4]， 当左右树都不平衡时，最后root会返回平衡
    bool isBalanced(TreeNode* root) {
        return depth(root)==-1?false:true;
    }
    
private:
    int depth(TreeNode* root) {
        if(root==nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        
        if(abs(r-l)>1)
        return -1;
        return max(l,r)+1;
    }

//改正为o(n),实际运行是bottom up,每个点的高度返回给父节点，朝上传给root，只算root的高度，
//每个节点都只计算了一次（当然访问是先由上到下1次，然后计算的值逆推回去赋值访问1次，实际上是访问了2次）
//原算法慢在算完之后，再到父节点的父节点时，又要朝下计算一次，原因是每次都判断左右树是否平衡，而且上一步算得的父节点的高度没有存起来
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root)==-1?false:true;
    }
    
private:
    int depth(TreeNode* root) {
        if(root==nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        
        if(l==-1||r==-1||abs(r-l)>1) //蕴含的规则是，不仅左右子树的高度差不能大于1，且左右子树各自也要平衡
        return -1;
        return max(l,r)+1;
    }

};
