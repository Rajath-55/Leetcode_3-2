class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        if(nums.size() <= 2) return ans;
        for(int i = 0; i < nums.size() - 2; ++i){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            
            int start = i + 1, end = nums.size() - 1;
            
            while(start < end){
                int target = nums[start] + nums[i] + nums[end];
                if(target > 0) end--;
                else if(target < 0) start++;
                else{
                    cout<<target<<" "<<nums[i]<<" "<<nums[end]<<" "<<nums[start]<<"\n";
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start < end and nums[start] == nums[start + 1]) start++;
                    while(start < end and nums[end] == nums[end - 1]) end--;
                    start++;
                    end--;
                }
            }
        }
        
        return ans;
    }
};