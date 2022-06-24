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
    int result;
    
    int getSum(TreeNode *root){
        if(not root) return 0;
        
        int left = getSum(root->left);
        int right = getSum(root->right);
        
        int nodeInPath = max(max(left, right) + root->val, root->val);
        int nodeAsRoot = max(nodeInPath, left + right + root->val);
        result = max(result, nodeAsRoot);
        return nodeInPath;
    }
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        getSum(root);
        return result;
    }
};

/*
Path sum 
at any point, three cases could occur.
It is the root of the sum,
it is not in the sum,
it is in middle of the nodes in the sum.


*/