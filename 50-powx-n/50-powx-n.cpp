class Solution {
public:
    int temp;
//     double myPow(double x, int n) {
//         double ans = 1.0;
//         int temp = n;
//         long k = n;
//         if(n < 0) k*=-1;
//         while(k > 0){
//             if(k&1){
//                 ans *= x;
//             }
//             k>>= 1;
//             x = x*x;
//         }
        
//         return temp < 0 ? 1.0/ans : ans;
        
//     }
    double myPow(double x, int n) {
       if(n==0) return 1;
        
        double y = myPow(x,n/2);
        if(n%2==0){
            
            return y*y;
            
        }
        else{
            return n < 0 ? 1/x*y*y : x*y*y; 
        }
        
    }
    
};