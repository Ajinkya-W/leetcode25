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
    int dfsHelper(TreeNode* root, int &maxSum){
        if(!root) return 0;

        int leftMax = max(0, dfsHelper(root->left, maxSum));
        int rightMax = max(0, dfsHelper(root->right, maxSum));

        maxSum = max(maxSum, root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfsHelper(root, maxSum);
        return maxSum;
    }
};