class Solution {
public:
    int replace(int n){
        int ans = 0;
        while(n){
            int k = n%10;
            ans += k*k;
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        
        while(1){
            int replaced = replace(n);
            if(replaced == 1) return true;
            if(st.count(replaced)) return false;
            n = replaced;
            st.insert(n);
        }
        return false;
    }
};

/*
cycle detectione


*/