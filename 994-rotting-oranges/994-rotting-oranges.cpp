class Solution {
public:
    vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>>visited;
    int m,n;
    
    bool isValid(int i, int j, vector<vector<int>>grid){
        return (i >=0 and i < m and j >=0 and j < n and grid[i][j] == 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n;++j){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int res = 0;
        if(fresh == 0) return 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i < size; ++i){
                auto orange = q.front();
                q.pop();
                for(auto x : dirs){
                    int new_i = orange.first + x.first;
                    int new_j = orange.second + x.second;
                    if(isValid(new_i, new_j, grid)){
                        q.push({new_i, new_j});
                        grid[new_i][new_j] = 2;
                        fresh--;
                    }
                }
            }
            res++;
        }
        return (fresh ==0 ? --res : -1);
    
    }
};

/*

multi source bfs
queue<pair>etc
very imp q
add all rotten already first
then change adjacent ones and update count eneverytime you do so
standard bfs stuff

*/