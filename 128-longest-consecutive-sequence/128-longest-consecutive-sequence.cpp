class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        if(nums.empty()) return 0;
        vector<int>distinct;
        int ans = 1;
        int maxi = INT_MIN;
        
        for(auto x : nums) mp[x] = 1;
        
        for(auto x : mp) distinct.push_back(x.first);
        sort(distinct.begin(), distinct.end());
        
        int n = distinct.size();
        for(int i = 0; i < n - 1; ++i){
            if(distinct[i+1] != distinct[i] + 1){
                maxi = max(maxi, ans);
                ans = 1;
                continue;
            }
            ans++;
        }
        maxi = max(maxi, ans);
        return maxi;
        
        
        
        
    }
    
};