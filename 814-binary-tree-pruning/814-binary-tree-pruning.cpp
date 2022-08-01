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
    int dfs(TreeNode *root){
        if(not root) return 1;
        if(not root->left and not root->right){
            return root->val == 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left) root->left = nullptr;
        if(right) root->right = nullptr;
        
        return left and right and root->val == 0;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(not root) return root;
        auto ans = dfs(root);
        if(ans) return nullptr;
        return root;
    }
};