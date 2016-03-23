//这道题也是比较经典的题，涉及到root->leaf的这一个路径。
//方法有2，要么dfs（backtracking），要么分治recursive
//o(n)

//divide
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
    if(root== nullptr) return {};
    if(root->left==nullptr&&root->right==nullptr){
        return {to_string(root->val)};
    }
    
    vector<string> paths;
    // https://leetcode.com/discuss/52072/accepted-java-simple-solution-in-8-lines
    // or https://leetcode.com/discuss/56730/c-a-clean-one-function-approach
    for(auto & e: binaryTreePaths(root->left))
        paths.push_back(to_string(root->val) + "->" + e );
    for(auto & e: binaryTreePaths(root->right))
        paths.push_back(to_string(root->val) + "->" + e );
    return paths;
    }
};

//dfs(backtracking)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> path;
    if(root!=NULL) DFS(root, path, "");
    return path;
    }
private:
void DFS(TreeNode* root, vector<string>& path, const string & str){
    string str1= str + to_string(root->val); 
    if(root->left==NULL&&root->right==NULL)  path.push_back(str1);
    if(root->left) DFS(root->left, path,  str1 +  "->");
    if(root->right)DFS(root->right, path,  str1 +  "->");
}
};
//这里backtracking不明显，实质是因为传进来str,然后传下去str1
