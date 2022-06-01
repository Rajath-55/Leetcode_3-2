class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         vector<int>dp(nums.size(), 1);
        if(nums.size() == 1) return 1;
        dp[0] = 1;
        
        
        
        for(int i=1; i < nums.size(); ++i){
            int maxiNow = nums[i];
            for(int j = 0; j < i; ++j){
                if(nums[j] < maxiNow){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        
        
        return *max_element(dp.begin(), dp.end());
    }

};