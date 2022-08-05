class Solution {
public:
    vector<vector<int>>dp;
    
    int recurse(vector<int>&nums, int i, int j, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = -1e6;
        for(int k = i; k <= j; ++k){
            int cost = nums[i-1] * nums[k] * nums[j + 1] + recurse(nums, i, k - 1, dp) + recurse(nums, k + 1, j , dp);
            ans = max(ans, cost);
        }
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        dp.resize(n + 1, vector<int>(n + 1, -1));
        
        return recurse(nums, 1, n, dp);
    }
    
};