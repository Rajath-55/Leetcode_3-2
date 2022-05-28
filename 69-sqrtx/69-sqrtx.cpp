class Solution {
public:
    int mySqrt(int x) {
        long int low = 0, high = x;
        long int ans = 1;
        while(low <= high){
            long int mid = low + (high - low)/2;
            // cout<<mid*mid<<"\n";
            if(mid*mid == x) return mid;
            if(mid*mid < x){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            
        }
        return ans;
    }
};