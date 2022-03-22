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
		// if the root is null then robber cant rob anything
        if(root==NULL) return 0;
        // if we already have the solution, we will return it
        if(dp.count(root)) return dp[root];
        // grand children houses robbery
        int left_left_robbery = root->left ? rob(root->left->left) : 0;
        int left_right_robbery = root->left ? rob(root->left->right) : 0;
        int right_left_robbery = root->right ? rob(root->right->left) : 0;
        int right_right_robbery = root->right ? rob(root->right->right) : 0;
        // 2 possible choices (current house + grand children houses) or (children houses)
        int choice1 = root->val + left_left_robbery + left_right_robbery + right_left_robbery + right_right_robbery;
        int choice2 = rob(root->left) + rob(root->right);
        // store the result and return it.
        return dp[root] = max(choice1,choice2);
    }
};