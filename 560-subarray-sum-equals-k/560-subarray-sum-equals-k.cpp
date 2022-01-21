/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

1 3 6

O(N) time and space
Idea:
keep a map with running sum. At every point after updating sum, 
check if sum - target was seen before. If yes, add the count of the points where 
it was seen.
add the count of this new sum into the map for the future as well.

*/




class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]++;
        int ans = 0;
        
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum+=nums[i];
            if(mp.count(sum - k)) ans+=mp[sum-k];
            mp[sum]++;
        }
    
        return ans;
        
    }
};