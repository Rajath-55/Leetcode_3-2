class Solution {
public:
    vector<vector<int>>dp;
    vector<int>cache;
    
    int recurse(int idx, string s){
        if(idx == s.length() - 1 or dp[idx][s.length() - 1]) return 0;
        if(cache[idx] != -1) return cache[idx];
        
        int mini = s.length() - 1;
        
        for(int i = idx; i < s.length(); ++i){
            if(dp[idx][i]){
                mini = min(mini, 1 + recurse(i + 1, s));
            }
        }
        return cache[idx] = mini;
    }
    
    int minCut(string s) {
        int n = s.length();
        cache.resize(n, -1);
        dp.resize(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            int start = i, end = i;
            while(start >= 0 and end < n and s[start] == s[end]) dp[start--][end++] = 1;
            start = i;
            end = i + 1;
            while(start >= 0 and end < n and s[start] == s[end]) dp[start--][end++] = 1;
        }
        
        return recurse(0, s);
    }
};