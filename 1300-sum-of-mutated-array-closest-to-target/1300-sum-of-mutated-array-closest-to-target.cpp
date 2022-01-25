class Solution {
private:
    int find(int mid,vector<int>&arr,int target)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>=mid)
                sum+=mid;
            else
                sum+=arr[i];
        }
        return abs(sum-target);
    }
public:
    
    int findBestValue(vector<int>& arr, int target) {
        
        int n=arr.size();
        int low=0;
        int high=1e8;
        sort(arr.begin(),arr.end());
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            
            int e1=find(mid,arr,target);
            int e2=find(mid+1,arr,target);
            
            if(e1<=e2)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};