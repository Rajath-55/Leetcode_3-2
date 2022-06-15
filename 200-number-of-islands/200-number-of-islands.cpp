class Solution {
public:
    vector<pair<int,int>>dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    bool isPossible(int i, int j, int m, int n){
        return (i >= 0 and i < m and j >=0 and j < n);
    }
    
    void dfs(vector<vector<char>>&grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        
        for(auto x : dirs){
           int new_i = x.first + i;
           int new_j = x.second + j;
            // cout<<new_i<<" "<<new_j<<"\n";
            if(isPossible(new_i, new_j, m, n) and grid[new_i][new_j] == '1'){
                dfs(grid,new_i, new_j);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                cout<<grid[i][j]<<" ";
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
            cout<<"\n";
        }
        return ans;
    }
};