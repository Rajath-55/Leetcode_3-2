class Solution {
public:
    vector<vector<int>>dp;
    
    int dfs(int screen, int clipboard, int n){
        if(screen == n) return 0;
        
        if(screen > n) return INT_MAX;
        
        if(dp[screen][clipboard] != -1) return dp[screen][clipboard];
        
        // cout<<screen<<" "<<clipboard<<"\n";
        int copied = INT_MAX, notCopied = INT_MAX;
        
        
        
        copied = dfs(screen + clipboard, screen + clipboard, n);
        notCopied = dfs(screen + clipboard, clipboard, n);
        
        if(copied != INT_MAX) copied += 2;
        if(notCopied != INT_MAX) notCopied +=1;
        
        return dp[screen][clipboard] = min(copied, notCopied);
        
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        dp.resize(1001, vector<int>(1001, -1));
        
        return dfs(1, 1, n) + 1;
    }
};