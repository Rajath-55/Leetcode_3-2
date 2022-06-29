class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        while(left < right){
            ans = max(ans, nums[left++] + nums[right--]);
        }
        
        return ans;
    }
};

/*
2 3 3 5



*/