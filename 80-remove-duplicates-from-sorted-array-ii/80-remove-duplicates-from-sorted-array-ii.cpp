class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto x : nums){
            if(i < 2 or x > nums[i-2]) nums[i++]=x;
        }
        return i;
        
    }
};

/*

1 1 2 2 2 3 3 3 4 5 

1 1 2 2 

*/