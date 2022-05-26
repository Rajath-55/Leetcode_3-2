class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) return n;
        
        unordered_map<char,int>mp;
        
        int i = 0, j = 0;
        int maxi = 0;
        while(j < n){
            if(mp[s[j]] == 0){
                mp[s[j]]++;
                maxi = max(maxi, j - i + 1);
                j++;
                continue;
            }else{
               mp[s[i]]--;
               i++;
            }
        }
      return maxi;
    }
};