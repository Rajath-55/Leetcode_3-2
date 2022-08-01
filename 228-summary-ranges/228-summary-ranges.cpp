class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<string>ans;
        int start = nums[0], end = -1;
        string temp = "";
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[i-1] + 1){
                end = nums[i-1];
                if(start == end){
                    ans.push_back(to_string(start));
                }else{
                    ans.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
            }else{
                end = nums[i];
            }
        }
        if(start >= end){
            ans.push_back(to_string(start));
        }else{
            ans.push_back(to_string(start) + "->" + to_string(end));
        }
        
        return ans;
    }
};