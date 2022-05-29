class Solution {
public:
    int count;
    
    void backtrack(int idx, int n, vector<int>&vis){
        if(idx == n + 1){
            count++;
            return;
        }
        
        for(int i = 1; i <= n; ++i){
            if(vis[i]) continue;
            
            if(i%idx == 0 or idx%i == 0){
                vis[i] = 1;
                backtrack(idx + 1, n, vis);
                vis[i] = 0;
            }
        }
        
    }
    
    int countArrangement(int n) {
        //backtracking solution.
        count = 0;
        vector<int>vis(n+1);
        backtrack(1, n, vis);
        return count;
    }
};

/*
Construct a recursion tree and break if the condition fails
Permutations are generated and if you reach n numbers then count++;

*/