class Solution {
public:
    int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        verticalCuts.insert(verticalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long int maxH = 0, maxW = 0;
        for(int i = 1; i < horizontalCuts.size(); ++i){
            maxH = max(maxH, (long long)(horizontalCuts[i] - horizontalCuts[i-1]));
        }
         for(int i = 1; i < verticalCuts.size(); ++i){
            maxW = max(maxW, (long long)(verticalCuts[i] - verticalCuts[i-1]));
        }
        
        return maxH*maxW == 0 ? h*w%mod : maxH*maxW%mod;
    }
};