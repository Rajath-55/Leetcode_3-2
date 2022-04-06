class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>ss(26),tt(26);
        
        for(auto x :  s) ss[x-'a']++;
        for(auto x : t) tt[x-'a']++;
        
        for(int i = 0; i < 26; ++i){
            if(ss[i] != tt[i]) return false;
        }
        return true;
    }
};