class Solution {
public:
    vector<vector<int>>vis;
    vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int res;
    bool isPossible(int i, int j, int m, int n){
        return (i >= 0 and i < m and j >=0 and j < n);
    }
    
    void dfs(int i, int j, vector<vector<int>>&grid, int &curr){
        vis[i][j] = 1;
        curr += 1;
        for(auto x : dirs){
            int new_i = i + x.first, new_j = j + x.second;
            if(isPossible(new_i, new_j, grid.size(), grid[0].size()) and grid[new_i][new_j] == 1 and not vis[new_i][new_j]) 
                dfs(new_i, new_j, grid, curr);
        }
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        res = 0;
        vis.resize(grid.size(), vector<int>(grid[0].size()));
        
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(not vis[i][j] and grid[i][j] == 1){
                    int curr = 0;
                    dfs(i,j, grid, curr);
                    cout<<curr<<"\n";
                    res = max(res, curr);
                }
            }
        }
       
        return res;
    }
};