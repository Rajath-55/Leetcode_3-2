class Solution {
public:
    bool isPalindrome(int x) {
        string y = to_string(x);
        string z = y;
        reverse(z.begin(), z.end());
        
        return z == y;
    }
};