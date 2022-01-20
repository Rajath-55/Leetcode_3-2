/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

IMP : You can assume that you can always reach the last index.


2 3 1 1 4


Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


O(N) time, O(1) space.
Same as the dp, only that we know we only need two parameters, the current end of jumping,
and macimum we can jump from here.
EVery time we reach a current end of jump, update answer and make curernt end as maximum reachable.

*/


class Solution {
public:
    int jump(vector<int>& nums) {
        int maximumReachable = 0, endOfCurrent = 0;
        
        int answer = 0;
        
        for(int i = 0; i < nums.size() - 1; ++i){
            maximumReachable = max(maximumReachable, nums[i] + i);
            
            if(i == endOfCurrent){
                answer++;
                endOfCurrent = maximumReachable;
            }
            
        }
        return answer;
    }
};