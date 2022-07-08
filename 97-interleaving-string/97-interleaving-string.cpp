class Solution {
public:
    vector<vector<int>>dp;
    
    bool recurse(string s1, int i, string s2, int j, string s3){
        if(i == s1.length() and j == s2.length()){
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = false;
        if(i < s1.length() and s1[i] == s3[i + j]){
            ans = ans || recurse(s1, i + 1, s2, j, s3);
        }
        if(j < s2.length() and s2[j] == s3[i + j]){
            ans = ans || recurse(s1, i, s2, j + 1, s3);
        }
        return dp[i][j] = ans;
        
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(101, vector<int>(101, -1));
        if(s3.length() != s1.length() + s2.length()) return false;
        return recurse(s1, 0, s2, 0, s3);
    }
};


/*
pick from string 1 or pick from string 2.


*/