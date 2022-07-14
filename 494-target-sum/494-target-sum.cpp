class Solution {
public:
    vector<vector<int>>dp;
    
    int dfs(vector<int>&nums, int target, int idx){
        if(idx == nums.size()) return target == 0;
        if(target < 0) return 0;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int take = dfs(nums, target - nums[idx], idx + 1);
        int dontTake = dfs(nums, target, idx + 1);
        return dp[idx][target] = take + dontTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto x : nums) sum+=x;
        if((sum + target)%2 == 1 or sum + target < 0 or target > sum) return 0;
        
        target = (sum + target)/2;
        dp.resize(nums.size(), vector<int>(target + 1, -1));
        return dfs(nums, target, 0);
        
    }
};