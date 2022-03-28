class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char,int>mp;
        if(s == "" or s == " ") return s.length();
        while(i < s.length()){
           if(mp[s[i]] == 0){
               ans = max(ans, i - j + 1);
               mp[s[i]]++;
               i++;
           }else{
               mp[s[j]]--;
               j++;
           }
        }
        return ans;
    }
};