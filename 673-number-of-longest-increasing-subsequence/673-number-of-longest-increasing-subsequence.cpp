class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        vector<int>count(nums.size(),1);
        
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    if(dp[i] == dp[j] + 1) count[i] += count[j];
                    else if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    
                }
            }
        }
        
        for(auto x : dp) cout<<x<<" ";
        int maxi = *max_element(dp.begin(), dp.end());
        int ans = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(dp[i] == maxi) ans += count[i];
        }
        return ans;
    }
};