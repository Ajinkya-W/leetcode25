/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int prev, int len, int& ans) {
        // base condition
        if (!root) {
            ans = max(ans, len);
            len = 1;
            return;
        }
        if (root->val == prev + 1)
            len++;
        else
            len = 1;

        ans = max(ans, len);

        if (root->left)
            dfs(root->left, root->val, len, ans);
        if (root->right)
            dfs(root->right, root->val, len, ans);
    }
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val - 1, 0, ans);
        return ans;
    }
};