class Solution {
public:
    int count;
    
    void merge(vector<int>&nums, int start, int mid, int end){
        // two pointers;
        int l = start, r = mid + 1;
        while(l <= mid && r <= end){
            if((long)nums[l] > (long) 2 * nums[r]){
                count += (mid - l + 1);
                r++;
            }else{
                l++;
            }
        }
       // worst case might be nlog(n) 
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
    }
    
    void mergeSort(vector<int>&nums, int start, int end){
        if(end == start) return;
        
        int mid = start + (end - start)/2;
        
        mergeSort(nums,start, mid); 
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
    
};