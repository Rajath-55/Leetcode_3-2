class Solution {
public:
    vector<int>ans;
    
    int dfs(int i, int j, vector<vector<int>>&grid){
        if(j < 0 or j >= grid[0].size()) return -1;
        
        if(i == grid.size()){
            return j;
        }
        
        if(grid[i][j] == 1){
            if(j + 1 < grid[0].size()){
                if(grid[i][j + 1] == -1) return -1;
                return dfs(i + 1, j + 1, grid);
            }
        }
        if(grid[i][j] == -1){
            if(j - 1 >= 0){
                if(grid[i][j-1] == 1) return -1;
                return dfs(i + 1, j - 1, grid);
            }
            
        }
        return -1;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        ans.resize(n,-1);
        
        for(int i = 0; i < n; ++i){
            ans[i] = dfs(0, i, grid);
        }
        return ans;
        
        
    }
};