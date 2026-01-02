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
class BSTIterator {
private:
    stack<TreeNode*> stkLeft, stkRight;
    void pushAllLeft(TreeNode* root){
        while(root){
            stkLeft.push(root);
            root = root->left;
        }
    }
    void pushAllRight(TreeNode* root){
        while(root){
            stkRight.push(root);
            root = root->right;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
        pushAllRight(root);
    }
    
    int nextLeft() {
        TreeNode* top = stkLeft.top();
        stkLeft.pop();
        if(top->right){
            pushAllLeft(top->right);
        }
        return top->val;
    }
    
    int nextRight() {
        TreeNode* top = stkRight.top();
        stkRight.pop();
        if(top->left){
            pushAllRight(top->left);
        }
        return top->val;
    }
    
    bool hasNextLeft() {
        return !stkLeft.empty();;
    }

    bool hasNextRight() {
        return !stkRight.empty();;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        BSTIterator it(root);        
        int left = it.nextLeft(), right = it.nextRight();
        while(left < right){
            if(left + right == k)
                return true;
            if(left + right > k){
                right = it.nextRight();
            } else{
                left = it.nextLeft();
            }
        }
        return false;
    }
};