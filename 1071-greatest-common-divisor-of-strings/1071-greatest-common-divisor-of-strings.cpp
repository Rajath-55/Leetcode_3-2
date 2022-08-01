class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        int g = __gcd(n1, n2);
        
        return (str1 + str2 == str2 + str1) ? str1.substr(0, g) : "";
    }
};