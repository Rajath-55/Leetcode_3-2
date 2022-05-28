class Solution {
public:
    
    int lowerBound(vector<int>&nums, int target){
        int ans = -1;
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    int upperBound(vector<int>&nums, int target){
        int ans = -1; 
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                low = mid + 1;
                ans = mid;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        
        return ans;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans = {-1,-1};
        if(nums.empty()) return ans;
        
        int start = 0, end = nums.size() - 1;
        int lower = -1, upper = -1;
        
        // create two functions lower_bound and upper_bound 
        //lower_bound returns the last index of the element if found else -1
        // upper bound returns the first index of the element if found else -1;
        ans[0] = lowerBound(nums, target);
        ans[1] = upperBound(nums,target);
        return ans;
    }
};