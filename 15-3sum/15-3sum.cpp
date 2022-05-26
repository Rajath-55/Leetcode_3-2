class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            
            while(left < right){
                int currSum = nums[left] + nums[right] + nums[i];
                if(currSum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right and nums[left] == nums[left + 1]) left++;
                    while(left < right and nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                }else if(currSum > 0) right--;
                else left++;
                
            }
            
        }
        return ans;
        
    }
};

/*
[[]]
[-1,0,1,2,-1,-4]

target is 0

-1 0 1

-1 -1 2

-1 0 1 2 3 4




[[] []]


[0,0,0,0,0,0]
[0,0,0]

[ai < ai+1 < ai+2]

for each ai, we can now perform 2 sum strategy:
    which essentially was:
        get the two numbers summing to a target k
        in this case the target k will be -ai.

*/