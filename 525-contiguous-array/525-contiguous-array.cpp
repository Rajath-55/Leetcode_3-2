class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto &x : nums) if(x == 0) x = -1;
        unordered_map<int,int>mp;

        
        mp[0] = -1;
        int sum = 0;
        int res = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            //cumulative sum
            sum+=nums[i];
            
            //check if value already exists in the map
            if(mp.find(sum) != mp.end()){
                //finding the length of possible subarray and comparing with the max result
                res=max(res,i-mp[sum]);
            }
            else{
                //adding value to our map
                mp[sum]=i;
            }
        }
        return res == INT_MIN ? 0 : res;
        
    }
};