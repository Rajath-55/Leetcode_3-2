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
    
    vector<TreeNode*>getTrees(int start, int end){
        if(start > end) return {NULL};
        vector<TreeNode*>ans;
        
        for(int i = start; i <= end; ++i){
            //root is i, left half has i-1 right half has n-i values
            auto leftHalf = getTrees(start, i - 1);
            auto rightHalf = getTrees(i + 1, end);
            
            for(auto l : leftHalf){
                for(auto r : rightHalf){
                    ans.push_back(new TreeNode(i, l, r));
                }
            }
            
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 1) return {new TreeNode(n)};
        return getTrees(1, n);
    }
};