class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        if(nums[0] == target) return 1;
        int sum = 0;
        
        int res = INT_MAX;
        
        while(i < nums.size()){
            sum += nums[i];
            
            while(sum >= target){
                res = min(res, i - j + 1);
                sum -= nums[j++];
            }
            
            i++;
        }
        return res == INT_MAX ? 0 : res;
    }
};