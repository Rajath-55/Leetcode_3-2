class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int res = 0;
        for(int i = 0; i < n; ++i){
            int target = k - nums[i];
            
            if(mp.count(target)){
                mp[target]--;
                res++;
                if(mp[target] == 0) mp.erase(target);
                continue;
            }
            
            
            mp[nums[i]]++;
        }
        return res;
    }
};