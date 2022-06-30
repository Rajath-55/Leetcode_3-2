class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() ==0)
            return 0;
        if (nums.size() == 1)
            return 1;
        sort(nums.begin(),nums.end());
        int maxSeq = 1;
        for(int i =0; i < nums.size()-1; i++)
        {
            int currentSeq = 1;    
            while(i < nums.size() -1 )
            {
                
                if(nums[i+1] == nums[i])
                {

                    i++;
                    continue;
                }
                if(nums[i+1] == nums[i]+1)
                {
                 
                    currentSeq++;
                    i++;
                }
                else
                {
                    
                    break;
                }
            }
            maxSeq = max(maxSeq,currentSeq);
        }
        return maxSeq;
        
    }
};