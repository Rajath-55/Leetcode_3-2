class Solution {
public:
    const int mod = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); ++i){
            int low = i + 1, high = arr.size() - 1;
            while(low < high){                
                int currTar = arr[i] + arr[low] + arr[high];
                if(currTar < target) low++;
                else if(currTar > target) high--;
                else{
                    if(arr[low] == arr[high]){
                        ans += (high - low + 1)*(high - low)/2;
                        ans%=mod;
                        break;
                    }else{
                        int left = 1, right = 1;
                        while(low < high - 1 and arr[low] == arr[low + 1]){
                            left++;
                            low++;
                        }
                        while(low < high - 1 and arr[high] == arr[high - 1]){
                            high--;
                            right++;
                        }
                        ans += left*right;
                        ans%=mod;
                        low++;
                        high--;
                    }
                }
            }
        }
        return ans%mod;
    }
};