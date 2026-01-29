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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int qSize = q.size();
            if(root->val%2==0) return false;
            level++;
            if (level % 2 == 0) {
                int prev = INT_MIN;
                for (int i = 0; i < qSize; i++) {
                    TreeNode* front = q.front();
                    q.pop();
                    TreeNode *left = front->left, *right = front->right;
                    if (left) {
                        if (left->val > prev && left->val % 2 != 0) {
                            q.push(left);
                            prev = left->val;
                        } else
                            return false;
                    }
                    if (right) {
                        if (right->val > prev && right->val % 2 != 0) {
                            q.push(right);
                            prev = right->val;
                        } else
                            return false;
                    }
                }
            } else {
                int prev = INT_MAX;
                for (int i = 0; i < qSize; i++) {
                    TreeNode* front = q.front();
                    q.pop();
                    TreeNode *left = front->left, *right = front->right;
                    if (left) {
                        if (left->val < prev && left->val % 2 == 0) {
                            q.push(left);
                            prev = left->val;
                        } else
                            return false;
                    }
                    if (right) {
                        if (right->val < prev && right->val % 2 == 0) {
                            q.push(right);
                            prev = right->val;
                        } else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};