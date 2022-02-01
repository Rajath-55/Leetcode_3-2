class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = 0, green = 0;
        for(auto x : nums){
            if(x == 0) red++;
            if(x == 1) blue++;
            if(x == 2) green++;
        }
        int idx = 0;
        while(red--) nums[idx++] = 0;
        while(blue--) nums[idx++] = 1;
        while(green--) nums[idx++] = 2;
        
    }
};