class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<string>>ans;
    void dfs(int start, vector<string>temp, string &s){
        if(start == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = start; i < s.length(); ++i){
            if(dp[start][i]){
                temp.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, temp, s);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n));
        
        for(int i = 0; i < n; ++i){
            int start = i, end = i;
            while(start >=0 and end < n and s[start] == s[end]){
                dp[start--][end++] = 1;
            }
            start = i;
            end = i + 1;
            while(start >=0 and end < n and s[start] == s[end]){
                dp[start--][end++] = 1;
            }
        }
        vector<string>temp;
        dfs(0, temp,s);
        return ans;
        
    }
};