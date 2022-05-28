class Solution {
public:
    
    inline int ceiling(int a, int b){
        return a%b ? a/b + 1 : a/b;
    }
    bool canEat(vector<int>&piles, int h, int k){
        int bananas = 0;
        int hours = 0;
        
        for(int i = piles.size() - 1; i >=0; --i){
            hours += ceiling(piles[i],k);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // int sum = 0;
        sort(piles.begin(), piles.end());
        // for(auto x : piles) sum+=x;
        int low = 1, high = 1e9;
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            bool isPossible = canEat(piles, h, mid);
            
            if(isPossible){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};