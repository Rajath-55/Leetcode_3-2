class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = arr[n - 1];
        int sum = 0;
        int maxn = INT_MIN;
        for (auto val : arr) {
            sum += val;
            maxn = max(maxn, val);
        }
        
        if (sum <= target) return maxn;
        
        int diff = INT_MAX;
        int res = 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int tempSum = 0;
            for (int i = 0; i < arr.size(); ++i) {
                tempSum += arr[i] >= mid ? mid : arr[i];
            }
            tempSum >= target ? high = mid - 1 : low = mid + 1;
            
            if (abs(tempSum - target) < diff || (abs(tempSum - target) == diff && mid < res)) {
                res = mid;
                diff = abs(tempSum - target);
            }
        }
        
        return res;
    }
};