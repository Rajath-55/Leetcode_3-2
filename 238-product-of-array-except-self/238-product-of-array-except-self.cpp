/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre(nums.size()), suf(nums.size());
        
        pre[0] = nums[0];
        
        
        suf[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); ++i){
            pre[i] = pre[i-1]*nums[i];
        }
        for(int i = nums.size() - 2; i >=0; --i){
            suf[i] = suf[i+1]*nums[i];
        }
        
        vector<int>ans(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            if(i == 0) ans[i] = suf[1];
            else if(i == nums.size() - 1) ans[i] = pre[nums.size() - 2];
            else ans[i] = pre[i-1]*suf[i+1];
        }
        return ans;
    }
};