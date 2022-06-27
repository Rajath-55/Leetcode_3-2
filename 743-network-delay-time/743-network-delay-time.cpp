class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>shortest(n, INT_MAX);
        vector<vector<pair<int,int>>>graph(n);
        --k;
        for(auto x : times){
            graph[--x[0]].push_back({--x[1], x[2]});
            cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
        }
        
        priority_queue<pair<int,int>>pq;
        pq.push({0,k});
        shortest[k] = 0;
        
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            
            for(auto x : graph[node]){
                if(shortest[x.first] > shortest[node] + x.second){
                    shortest[x.first] = shortest[node] + x.second;
                    pq.push({-shortest[x.first], x.first});
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < n; ++i){
            // cout<<shortest[i]<<" ";
            if(shortest[i] == INT_MAX) return -1;
            ans = max(ans, shortest[i]);
        }
        return ans;
        
    }
};