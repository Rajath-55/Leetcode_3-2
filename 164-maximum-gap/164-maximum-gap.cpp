class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        for(int i = 1; i < nums.size(); ++i)
            maxi = max(maxi, nums[i] - nums[i-1]);
        
        return maxi == INT_MIN ? 0 : maxi;
    }
};