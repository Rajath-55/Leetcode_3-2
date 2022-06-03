class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
        for(auto x : tokens){
            if(x.length() > 1 or isdigit(x[0])){
                st.push(stoi(x));
                continue;
            }
            assert(st.size() >= 2);
            auto op1 = st.top(); st.pop();
            auto op2 = st.top(); st.pop();
            int res = 0;
            if(x[0] == '+') res = op2 + op1;
            if(x[0] == '-') res = op2 - op1;
            if(x[0] == '*') res = op2*op1;
            if(x[0] == '/') res = op2/op1;
            st.push(res);
        }
        return st.top();
    }
};