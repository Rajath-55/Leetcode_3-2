class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(auto i : s){
            v[i-'a']++;
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        unordered_set<int> st;
        int c=0;
        for(auto &i : v){
            if(i==0) break;
            while(st.find(i)!=st.end()){
                i--;
                c++;
            }
            if(i>0) st.insert(i); 
        }
        return c;
    }
};