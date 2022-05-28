class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        vector<int>left(n), right(n);
        int maxi = 0;
        
        //left = max until now from left to right
        // right = max until now from right to left
        for(int i = 0; i < n; ++i){
            left[i] = max(maxi, height[i]);
            maxi = left[i];
        }
        maxi = 0;
        for(int i = n - 1; i >=0; --i){
            right[i] = max(maxi, height[i]);
            maxi = right[i];
        }
        
        for(int i = 0; i < n; ++i){
            sum += abs(height[i] - min(left[i], right[i]));
        }
        return sum;
        
    }
};