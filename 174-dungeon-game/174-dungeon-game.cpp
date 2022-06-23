class Solution {
public:
    vector<vector<int>>dp;
    
    int recurse(int i, int j, vector<vector<int>>&dungeon){
        if(i >= dungeon.size() or j >= dungeon[0].size()) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == dungeon.size() - 1 and j == dungeon[0].size() - 1){
            return dungeon[i][j] < 0 ? abs(dungeon[i][j]) + 1 : 1;
        }
        
        int right = recurse(i + 1, j, dungeon);
        int down = recurse(i, j + 1, dungeon);
        
        int points = min(right, down) - dungeon[i][j];
        return dp[i][j] = (points <= 0 ? 1 : points);
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        return recurse(0,0,dungeon);
    }
};