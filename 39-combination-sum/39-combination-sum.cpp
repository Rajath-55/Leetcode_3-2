class Solution {
public:
    vector<vector<int>>ans;
    int target;
    
    void backtrack(vector<int>&candidates, vector<int>temp, int currSum, int idx){
        if(currSum == target){
            ans.push_back(temp);
            return;
        }
        if(currSum > target) return;
        if(idx == candidates.size()) return;
        
        for(int i = idx; i < candidates.size(); ++i){
            temp.push_back(candidates[i]);
            backtrack(candidates, temp, currSum + candidates[i], i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        vector<int>temp;
        this->target = target;
        backtrack(candidates, temp, 0, 0);
        return ans;
    }
};