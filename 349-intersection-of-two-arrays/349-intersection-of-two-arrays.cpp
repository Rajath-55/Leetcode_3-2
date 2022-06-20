class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1,st2;
        for(auto x : nums1) st1.insert(x);
        for(auto x : nums2) st2.insert(x);
        vector<int>res;
        for(auto x : st1){
            if(st2.count(x)) res.push_back(x);
        }
        return res;
        
    }
};