class Solution {
public:
    const int mod = (int)1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int>seats;
        for(int i = 0; i < corridor.size(); ++i){
            if(corridor[i] == 'S') seats.push_back(i);
        }
        long long ans = 1;
        int n = seats.size();
        if(n%2!=0 or n == 0) return 0;
        for(int i = 2; i < seats.size(); i+=2){
            ans *= (seats[i] - seats[i-1]);
            ans %=mod;
        }
        return (int)ans%mod;
    }
};