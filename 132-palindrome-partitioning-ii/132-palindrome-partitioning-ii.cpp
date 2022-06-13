class Solution {
public:
    vector<vector<int>>isPal;
    int ans;
    vector<int>cache;
    void filldp(string s){
        for(int i = 0; i < s.length(); ++i){
            int start = i, end = i;
            while(start >= 0 and end < s.length() and s[start] == s[end]) isPal[start--][end++] = 1;
            start = i;
            end = i + 1;
            while(start >= 0 and end < s.length() and s[start] == s[end]) isPal[start--][end++] = 1;
        }
    }
    
    int recurse(string s, int start){
        if(start == s.length() - 1 or isPal[start][s.length() - 1]) return 0;
        
        if(cache[start] != -1) return cache[start];
        
        int minCuts = s.length() - 1;
        
        for(int i = start; i < s.length(); ++i){
            if(isPal[start][i]){
                minCuts = min(minCuts, 1 + recurse(s, i + 1));
            }
        }
        return cache[start] = minCuts;
        
    }
    
    
    int minCut(string s) {
        int n = s.length();
        ans = 0;
        isPal.resize(n + 1, vector<int>(n + 1));
        cache.resize(n + 1, -1);
        filldp(s);
        
        return recurse(s, 0);
    }
};