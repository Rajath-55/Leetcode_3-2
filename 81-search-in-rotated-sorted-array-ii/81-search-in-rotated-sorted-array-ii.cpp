class Solution {
public:
    bool search(vector<int>& nums, int target) {
         long int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            long int mid = low + (high - low)/2;
            
            if(nums[mid] == target) return true;
            //when duplicates exist 
             if((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }
            
            else if(nums[low] <= nums[mid]){
                if(target > nums[mid] or target < nums[low]) low = mid + 1;
                else high = mid - 1;
            }else{
                if(target < nums[mid] or target > nums[high]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return false;
    }
};