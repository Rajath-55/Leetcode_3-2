class Solution {
public:
    int dp[1001][101][2];
    
    int recurse(int transactions, vector<int>&prices, int idx, int buy){
        if(idx == prices.size()) return 0;
        if(transactions <= 0) return 0;
        if(dp[idx][transactions][buy] != -1) return dp[idx][transactions][buy];
        
        if(buy){
            //can buy so choice is buy or continue 
            int buyAndGo = -prices[idx] + recurse(transactions, prices, idx + 1, 0);
            int dontBuy = recurse(transactions, prices, idx + 1, 1);
            return dp[idx][transactions][buy] = max(buyAndGo, dontBuy);
        }
        
        int sellAndGo = prices[idx] + recurse(transactions - 1, prices, idx + 1, 1);
        int dontSell = recurse(transactions, prices, idx + 1, 0);
        return dp[idx][transactions][buy] = max(sellAndGo, dontSell);
        
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        
        return recurse(k, prices, 0, 1);
    }
};