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
    struct Result{
        int excluded;
        int included;
    };
    Result robDFS(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        Result left = robDFS(root->left);
        Result right = robDFS(root->right);

        int withMeSum = root->val + left.excluded + right.excluded;
    
        int withoutMeSum = max(left.excluded, left.included) + max(right.excluded, right.included);

        return {withoutMeSum, withMeSum};
    }
public:
    int rob(TreeNode* root) {
        Result answer = robDFS(root);
        return max(answer.included, answer.excluded);
    }
};