class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<string>>ans;
    void backtrack(vector<string>&temp, int idx, string s){
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.length(); ++i){
            if(dp[idx][i]){
                temp.push_back(s.substr(idx, i - idx + 1));
                backtrack(temp, i + 1, s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            int start = i, end = i;
            while(start >= 0 and end < n and s[start] == s[end]){
                dp[start][end] = 1;
                start--;
                end++;
            }
            start = i;
            end = i + 1;
            while(start >= 0 and end < n and s[start] == s[end]){
                dp[start][end] = 1;
                start--;
                end++;
            }
        }
        vector<string>temp;
        backtrack(temp, 0, s);
        return ans;
    }
};