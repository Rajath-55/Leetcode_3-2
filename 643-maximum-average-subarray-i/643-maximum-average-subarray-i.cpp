class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int currSum = 0, maxSum = INT_MIN;
        
        for(int i = 0; i < k; ++i) currSum += nums[i];
        maxSum = currSum;
        
        for(int i = k; i < nums.size(); ++i){
            currSum = currSum + nums[i] - nums[i-k];
            maxSum = max(maxSum, currSum);
        }
        return (double) maxSum/k;
        
    }
};

/*
1 12 -5 -6
12 -5 -6 50
-5 -6 50 3


*/