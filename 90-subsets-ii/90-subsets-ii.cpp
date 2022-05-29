class Solution {
public:
    vector<vector<int>>res;
    
    void recurse(vector<int>&nums, vector<int>&vec, int idx){
        res.push_back(vec);
		for (int i = idx; i != nums.size(); ++i)
			if (i == idx || nums[i] != nums[i - 1]) { 
				vec.push_back(nums[i]);
				recurse( nums, vec, i + 1);
				vec.pop_back();
			}
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        recurse(nums, temp, 0);
        return res;
    }
};