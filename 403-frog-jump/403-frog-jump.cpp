class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(), vector<int>(stones.size() + 1));
        
        dp[0][1] = 1;
        
        for(int i = 1; i < stones.size(); ++i){
            for(int j = 0; j < i; ++j){
                int dist = stones[i] - stones[j];
                if(dist >= stones.size() or !dp[j][dist] or dist < 0) continue;
                
                dp[i][dist] = 1;
                if(dist > 0) dp[i][dist - 1] = 1;
                if(dist < stones.size() - 1) dp[i][dist + 1] = true;
                if(i == stones.size() - 1) return true;
            }
        }
        
        return false;
        
    }
};
