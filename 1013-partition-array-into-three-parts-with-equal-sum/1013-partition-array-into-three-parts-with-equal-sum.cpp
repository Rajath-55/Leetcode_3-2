class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum%3) return false;
        
        int target = sum/3;
        int count = 0;
        int curr = 0;
        
        for(int i = 0; i < arr.size(); ++i){
            curr+=arr[i];
            if(curr == target){
                count++;
                curr = 0;
            }
        }
        return count >=3;
    }
};