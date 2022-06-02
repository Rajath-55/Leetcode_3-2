class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto &x : nums) if(x == 0) x = -1;
        unordered_map<int,int>mp;
        mp[0] = -1;
        int ans = 0;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(mp.count(sum)){
                ans = max(ans, abs(i - mp[sum]));
            }else{
                mp[sum] = i;
            }
        }
        return ans;
        
        
    }
};

/*
[0,1,0,0,1,0,1,0,1]

[-1,1,-1,-1,1,-1,1,-1,1]

i = 0, j = 0;


*/