class Solution {
public:
    
    static bool custom(const string &a, const string &b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
        int n = nums.size(), zero = 0;
        for(auto x : nums) if(x == 0) zero++;
       
        if(zero == n){
            // cout<<"HmMM";
            return "0";
        }
        vector<string>res;
        for(auto x : nums) res.push_back(to_string(x));
        
        sort(res.begin(), res.end(), custom);
        
        for(auto x : res) ans+=x;
        
        return ans;
    }
};