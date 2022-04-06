class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        
        for(auto x : strs){
            string temp = x;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};