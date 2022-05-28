class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[low] <= nums[mid]){
                if(target > nums[mid] or target < nums[low]) low = mid + 1;
                else high = mid - 1;
            }else{
                if(target < nums[mid] or target > nums[high]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};

/*

find where the rotation occurs.

4 5 6 7 0 1 2

mid = 7
7 > 4 yes
7 < 2 so rotation is after 7
move low = mid + 1.




*/