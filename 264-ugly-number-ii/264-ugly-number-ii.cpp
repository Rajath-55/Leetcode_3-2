class Solution {
public:
    #define ull unsigned long long
    ull nthUglyNumber(ull n) {
        priority_queue<ull,vector<ull>,greater<ull>>pq;
        unordered_set<ull>st;
        
        pq.push(1);
        ull ans = n;
        st.insert(1);
        
        ull top = 1;
        while(n--){
            top = pq.top();
            pq.pop();
            if(st.count(top*2) == 0){
                pq.push(top*2);
                st.insert(top*2);
            }
            if(st.count(top*3) == 0){
                pq.push(top*3);
                st.insert(top*3);
            }
            if(st.count(top*5) == 0){
                pq.push(top*5);
                st.insert(top*5);
            }
        }
        return top;
    }
};