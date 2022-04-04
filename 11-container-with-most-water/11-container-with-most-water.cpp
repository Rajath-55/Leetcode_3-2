class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while(left <= right){
            ans = max(ans, min(height[left], height[right])*(right - left));
            
            if(height[left] < height[right]) left++;
            else if(height[right] < height[left]) right--;
            else{
                left++;
                right--;
            }
        }
        return ans;
    }
};