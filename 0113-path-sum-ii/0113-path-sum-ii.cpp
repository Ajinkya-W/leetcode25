/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, vector<int>& path, vector<vector<int>>& paths, int targetSum){
        if(!root) return;

        if(!root->left && !root->right){
            if(targetSum == root->val){
                path.push_back(root->val);
                paths.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        dfs(root->left, path, paths, targetSum - root->val);
        dfs(root->right, path, paths, targetSum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root, path, paths, targetSum);
        return paths;
    }
};