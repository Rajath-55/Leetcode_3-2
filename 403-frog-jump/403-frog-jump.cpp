class Solution {
public:
    unordered_map<long long, int> getID;
    vector<vector<int>> dp;
    vector<long long> a;
    int n;
    
    bool solve ( int i, int k ) {
        if ( i == n-1 ) return 1;
        if ( dp[i][k] != -1 ) return dp[i][k];
        
        bool ret = 0;
        long long g;
        
        g = a[i] + k - 1;
        int id = getID[g];
        if ( id != 0 && k-1 > 0 ) ret |= solve ( id, k-1 );
        
        g = a[i] + k;
        id = getID[g];
        if ( id != 0 && k > 0 ) ret |= solve ( id, k );
        
        g = a[i] + k + 1;
        id = getID[g];
        if ( id != 0 ) ret |= solve ( id, k+1 );
        
        return dp[i][k] = ret;
    }
    
    bool canCross(vector<int>& stones) {
        n = stones.size();
        
        for ( int i = 0; i < n; i++ ) {
            getID[stones[i]] = i;
            a.push_back ( stones[i] );
        }
        
        dp.resize( n, vector<int>(n, -1) );
        return solve ( 0, 0 );
    }
};