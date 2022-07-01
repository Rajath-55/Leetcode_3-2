class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_set<int>st;
        for(auto x : nums) st.insert(x);
        
        int i = 0; 
        int maxi = 1;
        while(i < nums.size()){
            if(!st.count(nums[i] - 1)){
                int curr = 1; 
                int temp = nums[i];
                while(st.count(temp + 1)){
                    temp++;
                    curr++;
                }
                maxi = max(maxi, curr);
            }
            i++;
        }
        return maxi;
    }
};