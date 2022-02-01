/*
Tortoise-hare algorithm


The idea is to build two pointers slow and fast, one moving twice as fast as the other. It is equivalent to finding the linked list cycle, and the point at which they intersect is the point which is duplicated.
*/




class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        fast = 0;
        while(1){
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast) break;
        }
        return slow;
        
    }
};