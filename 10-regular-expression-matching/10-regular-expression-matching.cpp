class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>>dp(n + 1, vector<int>(m+1));
        dp[n][m] = 1;
        
        for(int i = n; i >=0; --i){
            for(int j = m - 1; j >= 0; --j){
                bool match = (i < n and (p[j] == '.' or s[i] == p[j]));
                
                if(j < m - 1 and p[j + 1] == '*'){
                    dp[i][j] = dp[i][j+2] or (match and dp[i+1][j]);
                }else{
                    dp[i][j] = match and dp[i+1][j+1];
                }
                
            }
        }
        return dp[0][0];
    }
};