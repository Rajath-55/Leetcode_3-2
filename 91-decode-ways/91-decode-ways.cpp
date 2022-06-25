class Solution {
public:
    vector<int>dp;
    int res;
    int decodeWays(int start, string s){
        if(start >= s.length()){
            return 1;
        }
        if(s[start] == '0') return 0;
        
        if(dp[start] != -1) return dp[start];
        
        int ans = 0;
        if(start < s.length() - 1){
            int canBe = (s[start] - '0')*10 + s[start + 1] - '0';
            if(canBe >= 1 and canBe <= 26) ans += decodeWays(start + 2, s);
        }
        
        ans += decodeWays(start + 1, s);
        return dp[start] = ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        res = 0;
        dp.resize(n + 1, -1);
        int start = 0;
        if(s[0] == '0') return 0;
        return decodeWays(start, s);
    }
};