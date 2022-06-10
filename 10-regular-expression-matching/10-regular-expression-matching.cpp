class Solution {
public:
    string s,p;
    vector<vector<int>>dp;
    
    bool recurse(int sidx, int pidx){
        if(sidx >= s.length() and pidx >= p.length()) return true;
        if(pidx >= p.length()) return false;
        
        bool isEqual = sidx < s.length() and (s[sidx] == p[pidx] or p[pidx] == '.');
        
        if(pidx + 1 < p.length() and p[pidx + 1] == '*'){
            // go left (dont use the star), or right(use the star)
            if(recurse(sidx, pidx + 2) or (isEqual and recurse(sidx + 1, pidx))){
                return true;
            }
        }
        if(isEqual){
            return recurse(sidx+1, pidx + 1);
        }
        return false;
               
        
    }
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        int n = s.length(), m = p.length();
        dp.resize(n, vector<int>(m,-1));
        
        // every time we encounter a * we either use it (and check for previous character) or we dont use it.
        return recurse(0, 0);
    
        
    }
};