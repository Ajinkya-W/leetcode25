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
    int getHeight(TreeNode* root, int &maxDiameter){
        if(root == nullptr)
            return 0;
        
        int lh = getHeight(root->left, maxDiameter);
        int rh = getHeight(root->right, maxDiameter);
        
        int diameter = lh + rh;

        maxDiameter = max(maxDiameter, diameter);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        getHeight(root, maxDiameter);
        return maxDiameter;
    }
};