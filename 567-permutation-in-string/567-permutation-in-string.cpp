class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int>hs1(26),hs2(26);
        for(auto x : s1) hs1[x-'a']++;
        
        int i = 0, j = 0;
        
        while(j < s2.size()){
            hs2[s2[j] - 'a']++;
            int currSize = j - i + 1;
            if(currSize == s1.size()){
                if(hs1 == hs2) return true;
            }
            if(currSize < s1.size()) j++;
            else{
                hs2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};