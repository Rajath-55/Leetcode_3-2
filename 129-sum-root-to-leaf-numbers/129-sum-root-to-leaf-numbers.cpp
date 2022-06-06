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
    int ans;
    
    int dfs(TreeNode *root, int prev){
        if(not root) return 0;
        
        if(root->left == root->right){
            return prev*10 + root->val;
        }
        return dfs(root->left, prev*10 + root->val) + dfs(root->right, prev*10 + root->val);
        
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        ans = dfs(root, 0);
        return ans;
        
    }
};