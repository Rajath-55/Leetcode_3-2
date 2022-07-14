class Solution {
public:
    vector<vector<int>>dp;
    
    int dfs(vector<int>&A, int idx, int target){
        if(idx == A.size()) return target == 0;
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[idx][target] != -1) return dp[idx][target];
        
        return dp[idx][target] = dfs(A, idx + 1, target - A[idx]) || dfs(A, idx + 1, target);
    }
    bool canPartition(vector<int>& nums) {
        // sum of subsets are equal. 
        //partition implies that s1 U s2 = S 
        // let us consider the sum of subset one = two = x.
        // totalsum = 2x = A
        // A/2 possible as a subset.
        // this boils down to subset sum with total = A
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        sum/=2;
        dp.resize(nums.size(), vector<int>(sum*2, -1));
        return dfs(nums, 0, sum);
    }
};