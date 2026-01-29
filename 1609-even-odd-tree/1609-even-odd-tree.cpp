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
        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int qSize = q.size();

            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;

            bool isEvenLevel = (level % 2 == 0);
            
            for (int i = 0; i < qSize; i++) {
                TreeNode* front = q.front();
                q.pop();

                int currVal = front->val;

                if (isEvenLevel) {
                    if (currVal % 2 != 0 && currVal > prev) {
                        prev = currVal;
                    } else
                        return false;
                } else {
                    if (currVal % 2 == 0 && currVal < prev)
                        prev = currVal;
                    else
                        return false;
                }

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            level++;
        }
        return true;
    }
};