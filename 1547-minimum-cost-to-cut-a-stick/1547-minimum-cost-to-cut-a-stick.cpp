class Solution {
public:

    vector<vector<int>>dp;
    
    int recurse(vector<int>&cuts, int start, int end, int cstart, int cend){
        if(cstart > cend) return 0;
        if(dp[cstart][cend] != -1){
            return dp[cstart][cend];
        }
        
        int ans = INT_MAX;
        for(int i = cstart; i <= cend; ++i){
            int cutSize = end - start + recurse(cuts, start, cuts[i], cstart, i-1) + recurse(cuts, cuts[i], end, i+1,cend );
            ans = min(ans, cutSize);
        }
        return dp[cstart][cend] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        dp.resize(101, vector<int>(101, -1));
        sort(cuts.begin(), cuts.end());
        
        return recurse(cuts, 0, n, 0, cuts.size() - 1);
    }
    
};