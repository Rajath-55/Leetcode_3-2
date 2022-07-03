class Solution {
public:
    bool validPalindrome(string s) {
        // 2 pointer method
        int start = 0, end = s.length() - 1;
        int startFirst = 0, endFirst = 0;
        
        while(start < end){
            if(s[start] != s[end]){
                start++;
                startFirst++;
                continue;
            }
            end--;
            start++;
        }
        
        start = 0, end = s.length() - 1;
        while(start < end){
            if(s[start] != s[end]){
                end--;
                endFirst++;
                continue;
            }
            end--;
            start++;
        }
        return startFirst <= 1 or endFirst <= 1;
    }
};