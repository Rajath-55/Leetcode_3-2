class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int start = 0, end = 0;
        int count = 0, ans = 0;
        
        while(end < fruits.size()){
            mp[fruits[end]]++;
            
            if(mp.size() > 2){
                while(start <= end and mp.size() > 2){
                    mp[fruits[start]]--;
                    if(mp[fruits[start]] == 0){
                        mp.erase(fruits[start]);
                    }
                    start++;
                }
            }else{
                ans = max(ans, end - start + 1);
            }
            end++;
            
        }
        return ans;
    }
    
};