class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 and i < m and j >= 0 and j < n);
    }
    vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        
        queue<pair<int,int>>q;
        q.push({sr, sc});
        int start = image[sr][sc];
        if(color == start) return image;
        
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            cout<<i<<" "<<j<<"\n";
            image[i][j] = color;
            for(auto x : dirs){
                int new_i = i + x.first;
                int new_j = j + x.second;
                if(isValid(new_i, new_j, m, n) and image[new_i][new_j] == start){
                    q.push({new_i, new_j});
                }
            }
            
        }
        return image;
    }
};