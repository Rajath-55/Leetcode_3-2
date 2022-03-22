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
    unordered_map<TreeNode*,int> dp;
    
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        
        int takeRoot = root->val + (root->left ? rob(root->left->left) + rob(root->left->right) : 0) + (root->right ? rob(root->right->left) + rob(root->right->right) : 0);
        int dontTakeRoot = rob(root->left) + rob(root->right);
        
        return dp[root] = max(takeRoot, dontTakeRoot);
    }
    
};