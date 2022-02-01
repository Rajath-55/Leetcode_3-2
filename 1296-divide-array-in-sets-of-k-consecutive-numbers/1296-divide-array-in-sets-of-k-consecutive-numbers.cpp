/*
treemap based solution, every time check if temp.back + 1 ie next consecutive number is there in the list
if its there then keep adding it until k elements are reached
if cant reach k elements or if temp.back + 1 not there return false
and update map on the way as well

*/


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto x : nums) mp[x]++;
        
        while(mp.size()){
            vector<int>temp;
            
            for(auto &x : mp){
                if(temp.size() >=k) break;
                if(temp.size() and x.first != temp.back() + 1) return false;
                
                temp.push_back(x.first);
                x.second--;
                if(x.second == 0){
                    mp.erase(x.first);
                }
            }
            if(temp.size() < k) return false; 
        }
        return true;
    }
};