class Solution {
public:
    int ans;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        ans = 0;
        vector<vector<int>>adj(n);
        
        for(int i = 0; i < n; ++i){
            if(i == headID) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({headID, 0});
        
        while(!q.empty()){
            auto [next, time] = q.front();
            
            q.pop();
            ans = max(ans, time);
            for(auto x : adj[next]){
                q.push({x, time + informTime[next]});
            }
        }
        return ans;
        
        
        
    }
};