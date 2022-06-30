class Solution {
public:

    void dfs(vector<vector<int>>& m,int vertex,vector<bool> & visited){
        visited[vertex]=true;
        for(int j=0;j<m.size();j++){ //yha par for each loop kaam ni krrha tha eg for(int child:m[vertex]) ni chla idhar
            if(!visited[j] && m[vertex][j]==1)
                dfs(m,j,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& m) {
           vector<bool> visited(m.size(),false);
        int count=0;
        for(int i=0;i<m.size();i++){
            if(!visited[i]){
              count++; 
                dfs(m,i,visited);
            }      
        }
        return count;
    }
};