class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2));
        dp[0][0] = dp[0][1] = 1;
        
        if(n <= 1) return n;
        
        for(int i = 1; i < n; ++i){
            int currNum = nums[i];
            for(int j = 0; j < i; ++j){
                if(currNum < nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                if(currNum > nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        int res = 0, maxi1 = 0, maxi2 = 0;
        for(auto x : dp){
            maxi1 = max(maxi1, x[0]);
            maxi2 = max(maxi2, x[1]);
        }
        
        res = max(maxi1, maxi2);
        return res;
        
    }
};

/*
variation of length of longest increasing subsequence.
dp[i][j] = lis with i elements j = 0 -> positive last
1 -> negative last.



*/