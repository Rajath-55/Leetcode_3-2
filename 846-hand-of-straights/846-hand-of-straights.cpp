class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(auto x : hand) mp[x]++;
        
        while(mp.size()){
            vector<int>temp;
            for(auto &x : mp){
                if(temp.size() >=groupSize) break;
                
                if(temp.size() and temp.back() + 1 != x.first) return false;
                
                temp.push_back(x.first);
                x.second--;
                if(x.second == 0) mp.erase(x.first);
            }
            if(temp.size() < groupSize) return false;
        }
        return true;
    }
    
};