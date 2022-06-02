class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<unordered_set<int>>dp(n);
        
        dp[0].insert(1);
        
        for(int i = 1; i < stones.size(); ++i){
            for(int j = 0; j < i; ++j){
                int dist = stones[i] - stones[j];
                if(!dp[j].count(dist)) continue;
                dp[i].insert(dist);
                if(dist + 1 < n) dp[i].insert(dist + 1);
                if(dist - 1 >= 0) dp[i].insert(dist - 1);
            }
        }
        return !dp[n-1].empty();
        
        
    }
};