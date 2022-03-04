class Solution {
public:
    vector<int>temp;
    
    //recursive solution O(2^n) time.
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
    
    void iterative(vector<vector<int>>&ans, vector<int>nums){
        int size = 1 << (int)nums.size();
        
        for(int i = 0; i < size; ++i){
            int k = i;
            vector<int>temp;
            int idx = 0;
            while(k){
                int bit = k&1;
                if(bit) temp.push_back(nums[idx]);
                idx++;
                k >>=1;
            }
            ans.push_back(temp);
            
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        // recurse(ans, nums, 0);
        iterative(ans, nums);
        return ans;
    }
};