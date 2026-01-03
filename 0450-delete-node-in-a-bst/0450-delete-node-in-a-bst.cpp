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
    TreeNode* deleteNode1(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found: Cases 1 & 2 (0 or 1 child)
            if (!root->left || !root->right) {
                TreeNode* temp = root->left ? root->left : root->right;
                delete root; 
                return temp;
            }
            
            // Case 3 (2 children): Swap with Successor
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left;
            
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Cases 0 & 1: No child or 1 child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Two children (Physically Move Successor)
            // 1. Find the parent of the successor
            TreeNode* succParent = root;
            TreeNode* succ = root->right;
            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }

            // 2. Disconnect successor from its original parent
            if (succParent != root) {
                succParent->left = succ->right;
                succ->right = root->right; // Successor takes over old right subtree
            }

            // 3. Connect successor to old left subtree
            succ->left = root->left;

            // 4. Delete old root and return the successor as the new root
            delete root;
            return succ;
        }
        return root;
    }
};