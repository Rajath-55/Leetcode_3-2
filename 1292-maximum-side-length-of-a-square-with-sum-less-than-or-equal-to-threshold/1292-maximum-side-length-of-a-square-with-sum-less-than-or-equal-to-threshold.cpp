class Solution {
public:
    int mx;
    int n,m;
    
    bool ispossible(vector<vector<int>>& mat,int side){
        for(int i=0; i+side-1<n; i++){
            for(int j=0; j+side-1<m; j++){
                long long ans = 0;
                for(int k=0; k<side; k++){
                    if(j==0)ans += mat[i+k][j+side-1];
                    else ans += mat[i+k][j+side-1] - mat[i+k][j-1];
                }
                if(ans <= mx) return true;
            }
        }
        
        return false;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();
        mx = threshold;
        int low = 0;
        int high = min(n,m);
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(j!=0) mat[i][j] += mat[i][j-1];
       
        
        while(high>low and low+1!=high){
            int mid = (low+high)/2;
            if(ispossible(mat,mid)) low = mid;
            else high = mid-1;
        }
            
        if(ispossible(mat,high)) return high;
            
        return low;
    }
};