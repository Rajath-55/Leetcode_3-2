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
    int getLargestIndex(vector<int>&arr){
        int ele = *max_element(arr.begin(), arr.end());
        return find(arr.begin(), arr.end(), ele) - arr.begin();
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int idx = getLargestIndex(nums);
        TreeNode *root = new TreeNode(nums[idx]);
        if(idx == 0) root->left = nullptr;
        else{
            vector<int>leftHalf(nums.begin(), nums.begin() + idx);
            root->left = constructMaximumBinaryTree(leftHalf);
        }
        if(idx == nums.size() - 1) root->right = nullptr;
        else{
            vector<int>rightHalf(nums.begin() + idx + 1, nums.end());
            root->right = constructMaximumBinaryTree(rightHalf);
        }
        
        return root;
    }
};