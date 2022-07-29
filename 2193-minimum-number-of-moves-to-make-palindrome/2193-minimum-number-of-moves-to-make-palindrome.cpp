class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        int i = 0, j = s.size() - 1;
        
        while(i < j){
            int l = i, r = j;
            while(s[l] != s[r]) r--;
            
            if(l == r){
                ans++;
                swap(s[r], s[r+1]);
                continue;
            }
            while(r < j){
                ans++;
                swap(s[r], s[r+1]);
                r++;
            }
            i++;
            j--;
        }
        return ans;
    }
};