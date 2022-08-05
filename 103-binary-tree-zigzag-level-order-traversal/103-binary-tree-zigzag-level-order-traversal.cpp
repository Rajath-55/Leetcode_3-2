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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // handle the edge case for the input when the root is null:
        vector<vector<int>>zigzagList;
        if(root == nullptr){
            // we return an empty array.
            return zigzagList;
        }
        
        // level 1 -> (3) (order left to right)
        // level 2 -> (9,20) (order right to left).
        // level 3 -> (15, 7) (order left to right)   note: null children as they are not added into the level order traversal.
        queue<TreeNode*>q;
        q.push(root);
        bool isLeft = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int>levelOrderValues;
            
            for(int i = 0; i < size; ++i){
                TreeNode* front = q.front();
                q.pop();
                levelOrderValues.push_back(front->val);
                
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(!isLeft){
                reverse(levelOrderValues.begin(), levelOrderValues.end());
            }
            isLeft = !isLeft;
            zigzagList.push_back(levelOrderValues);
        }
        return zigzagList;
        
    }
};
/*
clarifying questions:
A node with value.
root = could be null.
[3] 
root = null -> The expected output is {{}};

perfect? complete? or any random binary tree.

3

9 20
  15 7.   -> [[3], [20, 9], [15,7]];
  
q -> (3)
in every iteration of the traversal, we pop all the elements in the current level, and add their children.

first iteration -> q = 3. Pop 3, add its children in left to right fashion. -> 9 20
second iteration -> q = 9 20 pop 9, add its non null children 20 pop 20 add its non null children, 15 7
third iteration -> q = 15 7 pop 15 add its non null children pop 7 add its non null children. -> empty.

We move out of the level order traversal loop because there are no more children to be added that are not null.

therefore now, we have to now store the elements in zigzag fashion, so we maintain a boolean isLeft.
isLeft is true -> we store elements as we add them into the temporary array.
else we reverse the array and store it.


*/