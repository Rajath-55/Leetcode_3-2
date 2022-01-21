/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0

O(N), O(1) space

Approach: check start and end variables where elements are not in increasing order from left to right.
Then there is still a chance that the elements to the left of the subarray we got are still greater than elements
in subarray and those to the right are less than. To account for that take max and min of elements in the subarray we get for now and check for left and right sides of it.
Update start and end and get ans

*/




class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1;
        
        if(nums.size() == 1) return 0;
        
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i-1]){
                start = i-1;
                break;
            }
        }
         if(start == -1) return 0;
      
        for(int j = nums.size() - 1; j >0; --j){
            if(nums[j] < nums[j-1]){
                end = j;
                break;
            }
        }
       

        int minRange = *min_element(nums.begin() + start, nums.begin() + end + 1);
        int maxRange = *max_element(nums.begin() + start, nums.begin() + end + 1);
        
        for(int i = 0; i < start; ++i){
            if(nums[i] > minRange){
                start = i; 
                maxRange = max(maxRange, nums[i]);
                break;
            }
        }
        for(int i = nums.size() - 1; i > end; --i){
            if(nums[i] < maxRange){
                end = i;
                break;
            }
        }
        cout<<minRange<<" "<<maxRange<<" "<<start<<" "<<end<<"\n";

        return end - start + 1;
        
    }
};