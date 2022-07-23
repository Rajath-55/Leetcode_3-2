class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        pref.resize(n,vector<int>(m));
        for(int i=0;i<n;i++)pref[i][0]=matrix[i][0];
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                pref[i][j]=pref[i][j-1]+matrix[i][j];
            }
        }        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        if(col1>0){
            for(int i=row1;i<=row2;i++){
                sum+=pref[i][col2]-pref[i][col1-1];
            }
        }
        else {
            for(int i=row1;i<=row2;i++){
                sum+=pref[i][col2];
            }
        }
        return sum;
    }
};