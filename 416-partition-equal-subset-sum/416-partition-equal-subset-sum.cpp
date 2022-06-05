class Solution {
public:

    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        int half = sum/2;
        vector<vector<int>>dp(n, vector<int>(half + 1));
        
        for(int i = 0; i < n; ++i) dp[i][0] = 1;
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= half; ++j){
                if(j - nums[i-1] >= 0){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][half] == 1;
        //choose elements to sum to half now that is the question.
        //dp[i][j] can we taje first i elements to sum j. 
        
        
    }
};