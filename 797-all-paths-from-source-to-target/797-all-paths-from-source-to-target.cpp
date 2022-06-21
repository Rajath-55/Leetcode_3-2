class Solution {
public:
    vector<vector<int>>ans;
    vector<int>vis;
    
    void dfs(int u, vector<int>&temp, vector<vector<int>>&graph){
        if(u == graph.size() - 1){
            ans.push_back(temp);
            return;
        }
        for(auto x : graph[u]){
            temp.push_back(x);
            dfs(x, temp, graph);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        temp.push_back(0);
        vis.resize(graph.size());
        dfs(0, temp, graph);
        return ans;
    }
};