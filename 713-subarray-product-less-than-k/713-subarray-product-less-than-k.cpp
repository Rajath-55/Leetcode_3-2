class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        if(k <= 1) return 0;
        
        long int prod = 1;
        int count = 0;
        
        while(right < nums.size()){
            prod *= nums[right];
            
            while(left <= right and prod >= k){
                prod/=nums[left++];
            }
            count += right - left + 1;
            right++;
            
        }
        return count;
        
        
        
    }
};