class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n == 0 || edges.empty()) return 1;
        vector<int>vis(n);
        vector<vector<int>>g(n);
        for(auto x : edges){
            g[--x[0]].push_back(--x[1]);
            g[x[1]].push_back(x[0]);
        }
        --target;
        queue<pair<int, double>>q;
        vis[0] = 1;
        q.push({0, 1.0});
        double ans = 0;
        
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; ++i){
                auto [node, prob] = q.front();
                cout<<node<<" "<<prob<<"\n";
                q.pop();
                
                vis[node] = 1;
                if(t == 0){
                    ans += node == target ? prob : 0;
                    continue;
                }
                int children = 0;
                for(auto &x : g[node]) children += !vis[x];
                
                if(children == 0){
                    ans += node == target ? prob : 0;
                }
                
                for(auto x : g[node]){
                    if(not vis[x]) q.push({x, prob/children});
                }
                
            }
            t--;
        }
        return ans;
        
    }
};