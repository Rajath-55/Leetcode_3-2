class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>ss,countT;
        for(auto x : t) countT[x]++;
        if(s.length() < t.length()) return "";
        if(s.length() == 1){
            return s == t ? s : "";
        }
        int j = 0;
        int have = 0, need = countT.size();
        int minLen = INT_MAX;
        string res = "";
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            ss[c]++;
            if(countT.count(c) and ss[c] == countT[c]){
                have++;
            }
            while(have == need){
                int currWindowLength = i - j + 1;
                if(currWindowLength < minLen){
                    minLen = currWindowLength;
                    res = s.substr(j, minLen);
                }
                ss[s[j]]--;
                if(countT.count(s[j]) and ss[s[j]] < countT[s[j]] ){
                    have--;
                }
                j++;
            }
        }
        return res;
    }
};
/*
add into map characters of t
iterate through s with two pointers, move the second pointer until we have all occurences of t.
if that is a perfect match ,update ans to be min of ans, this.
then update left pointer to the point until where theres' no change in occurences of t. 


*/
