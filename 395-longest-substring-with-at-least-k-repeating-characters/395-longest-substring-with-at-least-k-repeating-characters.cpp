class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        
        if(n == 0 || n < k) return 0;
        
        if(k <= 1) return n;
        
        unordered_map<int,int>mp;
        for(auto x : s) mp[x]++;
        
        int length = 0;
        
        while(length < n and mp[s[length]] >= k) length++;
        
        if(length >= n - 1) return length;
        
        //doing the split at the point where there is a break of character frequency.
        int n1 = longestSubstring(s.substr(0, length), k);
        while(length < n and mp[s[length]] < k) length++;
        int n2 = longestSubstring(s.substr(length), k);
        
        if(length >= n) n2 = 0;
        return max(n1 , n2);
        
    }
};