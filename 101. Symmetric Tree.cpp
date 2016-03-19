//这题也是比较训练思维和耐心
//有两类解法，recursive和iterative
//以下是我的总结：

// 1 recursive 采用same tree的方法
// a. root为空， return true;
// b. root不为空，左右子均为空，return true;
// c. 否则，左右子必须值相等，且左子树的左树和右子树的右树对称（不是相等），
//  左子树的右树和右子树的左树对称

bool isSysmetric(TreeNode* root) {
  if(root==nullptr) return true;
  return helper(root->left, root->right);
}

bool helper(TreeNode* r1, TreeNode* r2) {
  if(r1==nullptr && r2==nullptr)
    return true;
  if(r1&&r2&&r1->val==r2->val)
    return helper(r1->left, r2->right)&helper(r1->right, r2->left);
    
  return false;  
}
//复杂度应该是时间空间都是o(n)，因为每个点都要比较到

// 2 iterative [这个是最终优化版了，我觉得比较好记好理解]
//采用两个queue或stack,分别存左右树，顺序略为不同：
// lq先左后右，rq先右后左
// 设置两个指针，每次都从queue中取值出来比，相同（空或非空）则继续遍历插入新节点进行下一轮比较
// 否则return false

bool isSymetric(TreeNode* root) {
  if(root==nullptr) return true;
  TreeNode* left = root->left;
  TreeNode* right = root->right;
  queue<TreeNode*> lq, rq;
  lq.push(left);
  rq.push(right);
  
  while(!lq.empty()&&!rq.empty()) {
    left = lq.front(); lq.pop();
    right = rq.front(); rq.pop();
    
    if((left==nullptr&&right==nullptr) ||(left&&right&&left->val==right->val)){
      if(left) {//只有相等了才继续存，当然也可以把这两个if拿出去，也就多一次
        lq.push(left->left);
        lq.push(left->right);
      }
      
      if(right) {
        rq.push(right->right);
        rq.push(right->left);
      }
    } else
      return false;
  }
  
  return lq.empty()&rq.empty();
}

//复杂度时空也均为o(n)

// 2.2 Iterative还有一种方法是，按层traversal，为空的要存null，然后判断这一层是否palindrome
Do level order traversal with null marked as # and levels are separated by *
Now check if each level is a palindrome.

这里按层遍历的方法是，while中嵌套for（size=当前stack的大小）
//不过综合起来看，这种方法并不是最优，因为多了很多中间过程，比如构建一层的数组，然后去判断palindrome，而且null还要想办法表示（存string）
