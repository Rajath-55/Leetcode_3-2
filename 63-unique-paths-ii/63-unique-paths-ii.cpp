class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 or j == 0){
                   if(i == 0){
                       dp[i][j] = (j > 0) ? dp[i][j-1] && obstacleGrid[i][j] == 0 : obstacleGrid[i][j] == 0;
                   }
                    if(j == 0){
                         dp[i][j] = (i > 0) ? dp[i-1][j] && obstacleGrid[i][j] == 0 : obstacleGrid[i][j] == 0;
                    }
                }else{
                    if(obstacleGrid[i][j] == 0)
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};