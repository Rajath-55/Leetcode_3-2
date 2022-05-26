class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        vector<int>ans;
        
        
        for(int i = 0; i < nums.size(); ++i){
            while(!dq.empty() and dq.front().second <= i - k) dq.pop_front();
            while(!dq.empty() and dq.back().first <= nums[i]) dq.pop_back();
            dq.push_back({nums[i], i});
            if(i >= k - 1)
            ans.push_back(dq.front().first);
        }
        
        return ans;
        
      
    }
};