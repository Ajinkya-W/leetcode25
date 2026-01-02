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
    int dfsHelper(TreeNode* root, int &maxDiameter){
        if(!root) return 0;

        int leftHeight = dfsHelper(root->left, maxDiameter);
        int rightHeight = dfsHelper(root->right, maxDiameter);

        int diameter = leftHeight + rightHeight;
        maxDiameter = max(maxDiameter, diameter);

        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        dfsHelper(root, maxDiameter);
        return maxDiameter;
    }
};