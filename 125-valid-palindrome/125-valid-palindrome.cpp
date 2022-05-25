class Solution {
public:
    bool isPalindrome(string s) {
        // 2pointer not really more like.1 poiter
        int i = 0;
        bool isOdd = s.length()&1;
     
        string y = "";
        for(auto &x : s){
            if(x >= 'A' and x <= 'Z'){
                y += x - 'A' + 'a';
            }else if(x >='a' and x <='z') y+=x;
            else if(x >='0' and x <='9') y+=x;
        }
        int n = y.length();
        for(int i = 0; i < n; ++i){
            if(y[i] != y[n - i - 1]) return false;
        }
        
        return true;
        
    }
};