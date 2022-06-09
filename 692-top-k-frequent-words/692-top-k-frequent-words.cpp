class Solution {
public:
    unordered_map<string, int>mp;
    static bool customCompare(const pair<int,string>&a, const pair<int,string>&b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        if(words.empty()) return ans;
        
        
        for(auto x : words) mp[x]++;
        vector<pair<int,string>>vc;
        for(auto x : words) vc.push_back({mp[x], x});
        
        sort(vc.begin(), vc.end(), customCompare);
        ans.push_back(vc[0].second);
        
        for(int i = 1; i < vc.size(); ++i){
            if(ans.size() == k) break;
            while(i < vc.size() and vc[i].second == ans.back()) i++;
            
            if(i < vc.size()){
                ans.push_back(vc[i].second);
            }
            
        }
        return ans;
        
    }
};