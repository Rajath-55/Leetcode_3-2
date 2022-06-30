class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        set<int>st;
        for(auto x : nums) st.insert(x);
        int ans = 1;
        int maxi = 1;
        
        auto it = st.begin();
        int curr = *it;
        it++;
        while(it != st.end()){
            if(*it == curr + 1){
                cout<<*it<<"\n";
                curr = *it;
                ans++;
            }else{
                // cout<<maxi<<" "<<ans; 
                maxi = max(maxi, ans);
                curr = *it;
                ans = 1;
            }
            it++;
        }
        return max(maxi, ans);
        
    }
};