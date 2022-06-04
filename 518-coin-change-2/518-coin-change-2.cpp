class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans = 0;
        vector<int>dp(amount + 1);
        dp[0] = 1;
        for(auto x : coins){
            for(int amt = 0; amt <= amount; ++amt){
                if(amt - x >= 0){
                    dp[amt] += dp[amt - x];
                }
            }
        }
        return dp[amount];
    }
};