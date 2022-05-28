class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        //next greater, previous greater
        int n = heights.size();
        vector<int>left(n),right(n);

        
        for(int i = 0; i < n; ++i){
            while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            right[i] = st.empty() ? n-1 : st.top() - 1;
            st.push(i);
        }
        
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i){
            ans = max(ans, heights[i]*(right[i] - left[i] + 1));
        }
        return ans;
        
        
    }
};