class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long curr = INT_MIN, best = INT_MIN;
        for(int x : nums){
            curr = max(curr + x, (long)x);
            best = max(best, curr);
        }
        return best;
    }
};