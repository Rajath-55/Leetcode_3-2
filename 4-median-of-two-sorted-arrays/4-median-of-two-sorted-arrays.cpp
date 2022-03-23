class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int low1 = 0, high1 = nums1.size() - 1, low2 = 0, high2 = nums2.size() - 1;
        int m = nums1.size(), n = nums2.size();
//         if(nums1[high1] < nums2[low1]){
//             if((m+n)%2==0){
                
//             }
//         }
        
        vector<int>merge(m+n);
        int i = 0, j = 0;
        int k = 0;
        
        while(i < m and j < n){
            if(nums1[i] < nums2[j]) merge[k++] = nums1[i++];
            else merge[k++] = nums2[j++];
        }
        while(i < m) merge[k++] = nums1[i++];
        while(j < n) merge[k++] = nums2[j++];
        
        for(auto x : merge) cout<<x<<' ';
        return (m+n)&1 ? (double)merge[merge.size()/2] : (double)(merge[merge.size()/2] + merge[merge.size()/2 - 1])/2.0;
        
      
        
        
    }
};

/*
1 3
2


1 2 2 2 2 2

3 5 6 8


low1 = 0, low2 = 0, high1 = m-1, high2 = n-1


*/