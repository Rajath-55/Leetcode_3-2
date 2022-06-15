class Solution {
public:
    static bool customCompare(vector<int>&a, vector<int>&b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), customCompare);
        
        int total = 0;
        int ans = 0;
        for(int i = 0; i < boxTypes.size(); ++i){
            int temp = min(truckSize, boxTypes[i][0]);
            ans += temp*boxTypes[i][1];
            truckSize -= temp;
        }
        return ans;
    }
};