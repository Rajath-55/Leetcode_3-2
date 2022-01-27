class Solution {
public:
    static bool customCompare(const pair<int,int>&p1, const pair<int,int>&p2){
        if(p1.second == INT_MAX and p2.second == INT_MAX){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i = 0; i < arr2.size(); ++i){
            mp[arr2[i]] = i;
        }
        
        vector<pair<int,int>>res;
        for(int i = 0; i < arr1.size(); ++i){
            if(mp.count(arr1[i])){
                res.push_back({arr1[i], mp[arr1[i]]});
            }else{
                res.push_back({arr1[i], INT_MAX});
            }
        }
        sort(res.begin(), res.end(), customCompare);
        for(auto x : res) cout<<x.first<<" "<<x.second<<"\n";
        vector<int>ans;
        for(auto x : res) ans.push_back(x.first);
        return ans;
    }
};