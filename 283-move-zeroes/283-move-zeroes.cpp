class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //we know that we will have some k zeros.
        // move all elements behind and then make k zeros at the end.
        int j = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        for(int i = j; i < nums.size(); ++i){
            nums[i] = 0;
        }
        
        
    }
};

/*







*/