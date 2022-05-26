class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();
    
        for(int i = 0; i < n; ++i){
            while(nums[i] == val and i < n){
                nums[i] = nums[--n];
            }
        }
        return n;
        
         
    }
};