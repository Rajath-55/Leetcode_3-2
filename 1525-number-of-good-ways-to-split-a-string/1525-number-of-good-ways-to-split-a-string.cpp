class Solution {
public:
    int numSplits(string s) {
        vector<int>pre(s.length()), suff(s.length());
        unordered_set<int>temp;
        for(int i = 0; i < s.length(); ++i){
            temp.insert(s[i]);
            pre[i] = temp.size();
        }
        int count = 0;
        int n = s.length();
        temp.clear();
        for(int i = n - 1; i >= 0; --i){
            temp.insert(s[i]);
            suff[i] = temp.size();
        }
        
        for(int i = 1; i < n; ++i){
            if(pre[i-1] == suff[i]) count++;
        }
        
        return count;
        
        
    }
};