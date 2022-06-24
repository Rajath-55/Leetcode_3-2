class Solution {
public:
    
    vector<vector<int>>dp;
    
    int recurse(int start, int end){
        if(start > end) return 1;
        if(start == end) return 1;
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = 0;
        for(int i = start; i <= end; ++i){
            ans += recurse(start, i - 1)*recurse(i + 1, end);
        }
        return dp[start][end] = ans;
        
    }
    
    int numTrees(int n) {
        dp.resize(22, vector<int>(22, -1));
        return recurse(1, n);
    }
};