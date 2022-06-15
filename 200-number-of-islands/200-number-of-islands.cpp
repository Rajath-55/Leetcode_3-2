class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==1 && grid[0].size()==1) {
            if(grid[0][0]=='1')
                return 1;
            return 0;
        }
        int VERT = grid.size();
        int HORT = grid[0].size();
        int islandCount = 0;
        for(int i=0; i<VERT; i++) {
            for(int j=0; j<HORT; j++) {
                if(grid[i][j] == '1') {
                    islandCount++;
                    DepthFirst(grid, i, j, VERT, HORT);
                }
            }
        }    
        return islandCount;
    }
    void DepthFirst(vector<vector<char>>& grid, int i, int j, int VERT, int HORT) {
        if(i<0 || j<0 || i>(VERT-1) || j>(HORT-1) || grid[i][j] != '1')
            return; 
        if(grid[i][j] == '1') {
            grid[i][j] = '0';
            DepthFirst(grid, i+1, j, VERT, HORT);
            DepthFirst(grid, i-1, j, VERT, HORT);
            DepthFirst(grid, i, j+1, VERT, HORT);
            DepthFirst(grid, i, j-1, VERT, HORT);
        }
    }
};