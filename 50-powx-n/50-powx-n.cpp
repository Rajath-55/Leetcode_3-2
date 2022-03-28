class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int temp = n;
        long k = n;
        if(n < 0) k*=-1;
        while(k > 0){
            if(k&1){
                ans *= x;
            }
            k>>= 1;
            x = x*x;
        }
        
        return temp < 0 ? 1.0/ans : ans;
        
    }
};