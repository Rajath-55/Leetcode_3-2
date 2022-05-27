class Solution {
public:
    
    int getCount(vector<int>&nums, int k){
        unordered_map<int,int>mp;
        
        int j = 0; 
        int ans = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]]++;
            
            if(mp.size() <= k) ans += i - j + 1;
            else{
                while(j <= i and mp.size() > k){
                    mp[nums[j]]--;
                    if(mp[nums[j]] <= 0) mp.erase(nums[j]);
                    j++;
                }
                ans += i - j + 1;
            }
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getCount(nums, k) - getCount(nums, k-1);
    }
};