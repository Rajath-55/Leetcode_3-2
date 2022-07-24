class Solution {
public:
    vector<int>dp;
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>ans(n, -1);
        vector<int>path;
        dp.resize(n);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i]%nums[j] == 0){  
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        ans[i] = j;
                    }
                }
            }
        }
        int start = 0, maxi = 0;
        for(int i = 0; i < dp.size(); ++i){
            // cout<<dp[i]<<" ";
            if(dp[i] > maxi){
                start = i;
                maxi = dp[i];
            }
        }
        // path.push_back(nums[start]);
        while(start != -1){
            path.push_back(nums[start]);
            start = ans[start];
        }
        reverse(path.begin(), path.end());
        return path;
        
    }
};