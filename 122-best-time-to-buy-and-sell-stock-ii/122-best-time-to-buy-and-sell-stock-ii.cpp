class Solution {
public:
    vector<vector<int>>dp;
    
    int recurse(vector<int>&prices, int idx, int buy){
        if(idx == prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy){
            int take = - prices[idx] + recurse(prices, idx + 1, 0);
            int dontTake = recurse(prices, idx + 1, 1);
            return dp[idx][buy] = max(take, dontTake);
        }
        int sell = prices[idx] + recurse(prices, idx, 1);
        int dontSell = recurse(prices, idx + 1, 0);
        return dp[idx][buy] = max(sell, dontSell);
        
    }
    
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return recurse(prices, 0, 1);
        
    }
};

/*
if you have a stock you can
sell -> then buy or not buy and continue
keep it and continue

if you dont have a stock then you can 
buy 
continue


*/