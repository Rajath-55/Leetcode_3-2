class Solution {
public:
    static bool customCompare(const vector<int>&a, const vector<int>&b){
        return (a[0] - a[1] < b[0] - b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), customCompare);
        int ans = 0;
        for(int i = 0; i < costs.size(); ++i){
            ans += (i < costs.size() /2) ? costs[i][0] : costs[i][1];
        }
        return ans;
    }
};