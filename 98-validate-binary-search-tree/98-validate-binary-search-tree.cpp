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
class Info{
    int predecessor;
    int successor;
};

class Solution {
public:
    
    bool helper(TreeNode *root, long long mini, long long maxi){
         if(not root) return true;
        
        if(root->val <= mini or root->val >= maxi) return false;
        
        return helper(root->left, mini, root->val) and helper(root->right, root->val, maxi);
        
    }
    bool isValidBST(TreeNode* root) {
        
       return helper(root, LLONG_MIN, LLONG_MAX);
    }
};