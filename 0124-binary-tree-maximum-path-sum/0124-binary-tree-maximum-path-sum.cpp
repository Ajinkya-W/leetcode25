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
private:
    int dfs(TreeNode *root, int &maxSum){
        if(!root)
            return 0;

        int leftGain = max(0, dfs(root->left, maxSum));
        int rightGain = max(0, dfs(root->right, maxSum));

        int singlePathSum = max(leftGain, rightGain) + root->val;

        maxSum = max(maxSum, leftGain + rightGain + root->val);
        return singlePathSum;  
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ignore = dfs(root, maxSum);
        return maxSum;
    }
};