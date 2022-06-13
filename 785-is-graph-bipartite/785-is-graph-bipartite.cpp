class Solution {
public:
    vector<int>color;
    
    bool bfs(vector<vector<int>>&graph, int idx){
        queue<int>q;
        q.push(idx);
        color[idx] = 0; 
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            for(auto x : graph[front]){
                if(color[x] == -1){
                    color[x] = 1 - color[front];
                    q.push(x);
                }
                if(color[x] == color[front]) return false;
                
            }
        }
        return true;
    }
   
    bool isBipartite(vector<vector<int>>& graph) {
        color.resize(graph.size(), -1);
        
        for(int i = 0; i < graph.size(); ++i){
            if(color[i] == -1){
                if(!bfs(graph, i)) return false;
            }
        }
        
        return true;
    }
};