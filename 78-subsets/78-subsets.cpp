class Solution {
public:
    vector<int>temp;
    void recurse(vector<vector<int>>&ans, vector<int>nums, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        recurse(ans, nums, index + 1);
        temp.pop_back();
        recurse(ans, nums, index + 1);
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        recurse(ans, nums, 0);
        return ans;
    }
};