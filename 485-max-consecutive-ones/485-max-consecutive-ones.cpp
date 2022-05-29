class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = INT_MIN;
        
        int curr = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                curr++;
                continue;
            }else{
                maxi = max(maxi, curr);
                curr = 0;
            }
        }
        return maxi = max(maxi, curr);
    }
};