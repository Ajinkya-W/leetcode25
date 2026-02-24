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
    void dfs(TreeNode* root, long long currSum, unordered_map<long long, int>& prefixSum, int targetSum, int& pathCount){
        if(!root) return;
        currSum += root->val;
        if(prefixSum.count(currSum-targetSum)){
            pathCount += prefixSum[currSum-targetSum];
        }
        prefixSum[currSum]++;
        dfs(root->left, currSum, prefixSum, targetSum, pathCount);
        dfs(root->right, currSum, prefixSum, targetSum, pathCount);
        prefixSum[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        long long currSum = 0;
        int pathCount = 0;
        dfs(root, currSum, prefixSum, targetSum, pathCount);
        return pathCount;
    }
};