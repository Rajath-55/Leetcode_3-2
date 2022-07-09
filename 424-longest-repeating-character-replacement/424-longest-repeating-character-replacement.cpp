class Solution {
public:
    
    int characterReplacement(string s, int k) {
        vector<int>mp(26);
        int left = 0, right = 0, res = 0;
        
        for(right = 0; right < s.length(); ++right){
            mp[s[right] - 'A']++;
            
            while(right - left + 1 - *max_element(mp.begin(), mp.end()) > k) {
                mp[s[left++] - 'A']--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

/*

ABCVBCGD
K = 3




*/