class Solution {
public:
    bool isValid(string s) {
        if(s.length() <= 1) return false;
        unordered_map<char,char>mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        stack<char>st;
        
        for(auto x : s){
            if(mp.count(x)){
                if(st.empty() or st.top() != mp[x]) return false;
                st.pop();
            }else{
                st.push(x);
            }
        }
        return st.empty();
    }
};