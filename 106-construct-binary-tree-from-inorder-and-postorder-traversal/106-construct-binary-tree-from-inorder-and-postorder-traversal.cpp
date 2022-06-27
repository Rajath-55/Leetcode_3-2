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
    unordered_map<int,int>mp;
    int postIdx;
    TreeNode *recursiveBuild(vector<int>&inorder, int start, int end, vector<int>&postorder){
        if(postIdx < 0 or start > end) return nullptr;
     
        int x = postorder[postIdx--];
        
        TreeNode *root = new TreeNode(x);
        if(start == end) return root;
        int idx = mp[x];
        
        root->right = recursiveBuild(inorder, idx + 1, end, postorder);
        root->left = recursiveBuild(inorder, start, idx - 1, postorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        postIdx = postorder.size() - 1;
        return recursiveBuild(inorder, 0, inorder.size() - 1, postorder);
    }
};