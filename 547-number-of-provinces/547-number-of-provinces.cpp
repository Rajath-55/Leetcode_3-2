class Solution {
public:
    vector<int>parent,rank;
    int find(int a){
        if(parent[a] == -1) return a;
        return parent[a] = find(parent[a]);
    }
    
    void my_union(int a, int b){
        int para = find(a);
        int parb = find(b);
        
        // cout<<para<<" "<<parb<<"\n";
        if(para == parb) return;
        
       
        if(rank[para] < rank[parb]){
            parent[parb] = para;
            rank[parb] += rank[para];
        }else{
            parent[para] = parb;
            rank[para] += rank[parb];
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent.resize(isConnected.size(), -1);
        rank.resize(isConnected.size(), 0);
        
        for(int i = 0; i < isConnected.size(); ++i){
            for(int j = 0; j < isConnected[i].size(); ++j){
                if(isConnected[i][j]){
                    rank[i] = rank[j] = 1;
                    my_union(i, j);
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < parent.size(); ++i) ans += parent[i] == -1;
        return ans;
    }
    
};