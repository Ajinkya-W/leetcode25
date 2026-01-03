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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // iterative value update
        TreeNode *curr = root, *prev = nullptr;

        // 1. Locate the node and its parent
        while (curr && curr->val != key) {
            prev = curr;
            if (key < curr->val) curr = curr->left;
            else curr = curr->right;
        }

        if (!curr) return root; // Key not found

        // 2. If node has 2 children, convert to Case 1
        if (curr->left && curr->right) {
            TreeNode* p_succ = curr;
            TreeNode* succ = curr->right;
            while (succ->left) {
                p_succ = succ;
                succ = succ->left;
            }
            curr->val = succ->val; // Value swap
            curr = succ;           // Now we delete the successor instead
            prev = p_succ;         // Update parent to the successor's parent
        }

        // 3. Case 0 or 1 child (The actual deletion/re-linking)
        TreeNode* child = curr->left ? curr->left : curr->right;

        if (!prev) {
            root = child; // Deleting the root node itself
        } else {
            if (prev->left == curr) prev->left = child;
            else prev->right = child;
        }

        delete curr; // Memory cleanup
        return root;
    }
    TreeNode* deleteNode3(TreeNode* root, int key) {
        // iterative ptr updates [Gold standard]
        TreeNode *curr = root, *prev = nullptr;

        // 1. Locate target and its parent
        while (curr && curr->val != key) {
            prev = curr;
            curr = (key < curr->val) ? curr->left : curr->right;
        }
        if (!curr) return root;

        TreeNode *replacement;
        if (!curr->left || !curr->right) {
            // Case 1: 0 or 1 child - trivial re-link
            replacement = curr->left ? curr->left : curr->right;
        } else {
            // Case 2: 2 children - Find and physically move Successor
            TreeNode *p_succ = curr;
            TreeNode *succ = curr->right;
            while (succ->left) {
                p_succ = succ;
                succ = succ->left;
            }

            // Successor's right child moves to Successor's old spot
            if (p_succ != curr) {
                p_succ->left = succ->right;
                succ->right = curr->right;
            }
            succ->left = curr->left;
            replacement = succ;
        }

        // Connect replacement to the original parent
        if (!prev) root = replacement;
        else if (prev->left == curr) prev->left = replacement;
        else prev->right = replacement;

        delete curr;
        return root;
    }
    TreeNode* deleteNode1(TreeNode* root, int key) {
        // recursive value swap
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
    TreeNode* deleteNode2(TreeNode* root, int key) {
        // recursive pointer update
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