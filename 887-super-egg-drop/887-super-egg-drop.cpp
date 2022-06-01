class Solution {
public:
    int superEggDrop(int k, int n) {
        int m = 500;
        vector<vector<int>>dp(m + 1, vector<int>(k + 1, 0));
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= k; ++j){
                dp[i][j] = 1 + dp[i-1][j-1] + dp[i-1][j];
                if(dp[i][j] >= n) return i;
            }
        }
        return -1;
        
    }
};

/*
dp[i][j] = min no of moves to determine for i floors and j eggs.


*/