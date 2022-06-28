class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        
        vector<vector<int>>dp(stones.size() + 1, vector<int>(sum /2+ 1));
        
        for(int i = 0; i <= stones.size(); ++i) dp[i][0] = 1;
        
        for(int i = 1; i <= stones.size(); ++i){
            for(int j = 1; j <= sum/2; ++j){
                if(stones[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - stones[i-1]];
            }
        }
        
        for(int i = sum/2; i >=0; --i){
            if(dp[stones.size()][i]) return sum - 2*i;
        }
        return 0;
    }
};