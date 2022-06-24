class Solution {
public:
    vector<int>getHistogram(vector<vector<char>>&matrix, int m){
        vector<int>ans(matrix[0].size());
        vector<vector<int>>dp(m + 1, vector<int>(matrix[0].size()));
        
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(i == 0) dp[i][j] = matrix[i][j] == '1';
                else{
                    dp[i][j] = matrix[i][j] == '0' ? 0 : dp[i-1][j] + 1;
                }
            }
        }
        for(int i = 0; i < matrix[0].size(); ++i) ans[i] = dp[m][i];
        
        // for(auto x : ans) cout<<x<<" ";
        // cout<<"\n";
        return ans;
    }
    
    int maxArea(vector<int>&histogram){
        int ans = 0;
        stack<int>st;
        int n = histogram.size();
        vector<int>left(n), right(n);
        for(int i = 0; i < histogram.size(); ++i){
            while(!st.empty() and histogram[st.top()] >= histogram[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        
         while(!st.empty()) st.pop();
        
         for(int i = histogram.size() - 1; i >=0; --i){
            while(!st.empty() and histogram[st.top()] >= histogram[i]) st.pop();
            right[i] = st.empty() ? n-1 : st.top() - 1;
            st.push(i);
        }
        
        for(int i = 0; i < histogram.size(); ++i){
            int area = histogram[i]*(right[i] - left[i] + 1);
            // cout<<area<<"\n";
            ans = max(ans, area);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i){
            vector<int>histogram = getHistogram(matrix, i);
            ans = max(ans, maxArea(histogram));
        }
        return ans;
    }
};