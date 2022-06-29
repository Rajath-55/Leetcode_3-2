class Solution {
public:
    int recurse(vector<int>&days, vector<int>&costs, int idx, vector<int>&dp){
        if(idx >= days.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int oneDay = costs[0] + recurse(days, costs, idx + 1, dp);
        int sindex, tindex;
        for(sindex = idx; sindex < days.size() and days[sindex] - days[idx] < 7; ++sindex );

        int sevenDays = costs[1] + recurse(days, costs, sindex, dp);
       for(tindex = idx; tindex < days.size() and days[tindex] - days[idx] < 30; ++tindex );
        int thirtyDays = costs[2] + recurse(days, costs, tindex, dp);
        
        return dp[idx] = min({oneDay, sevenDays, thirtyDays});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(), -1);
        return recurse(days, costs, 0, dp);
        
        
    }
};