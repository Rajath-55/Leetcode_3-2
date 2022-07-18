class Solution {
public:
    unordered_map<int,int>cache, mp;
    
    int recurse(vector<int>&nums, int idx){
        if(idx == nums.size()) return 0;
        if(cache.count(idx)) return cache[idx];
        
        int newIdx = idx;
        while(newIdx < nums.size() and nums[newIdx] <= nums[idx] + 1) newIdx++;
        
        int dontTake = recurse(nums, idx + 1);
        int take = nums[idx]*mp[nums[idx]] + recurse(nums, newIdx);
        
        return cache[idx] = max(take, dontTake);
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(auto x : nums) mp[x]++;
        
        return recurse(nums, 0);
        
    }
};