class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(n < 2){
            return 0;
        }
        
        vector<int>suffix(n,1);
        
        suffix[n-1] = prices[n-1];
        
        
        
        //take the maximum of possible days to sell on the RHS (assuming this is being calculated for the second transaction)
        for(int i = n-2; i >=0; --i){
            suffix[i] = max(suffix[i+1], prices[i]);
        }
        
        //get maximum profit assuming B2 on the ith day:
        int minSoFar = min(prices[0], prices[1]);
        int profit = max(0, prices[1] - prices[0]);
        
        int res = profit;
        
        for(int i = 2; i < n; ++i){
            int currProfit = 0;
            
            if(i!=n-1) currProfit = max(0, suffix[i+1] - prices[i]);
            int netProfit = currProfit + profit;
            res = max(res, netProfit);
            
            profit = max(profit, prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }
        res = max(res, profit);
        
        return res;
        
    }
};