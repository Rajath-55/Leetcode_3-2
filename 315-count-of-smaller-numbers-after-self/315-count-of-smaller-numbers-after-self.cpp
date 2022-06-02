// class Solution {
// public:
//     vector<int>ans;
    
//     void merge(vector<pair<int,int>>&v, int start, int mid, int end){
//         vector<pair<int,int>>res;
//         int left = start, right = mid + 1;
        
//         //we are sorting in descending order NOTE THAT IT IS IMPORTANT 
//         while(left <= mid and right <= end){
//             if(v[left].first <= v[right].first){
//                 res.push_back(v[right++]);
//             }else{
//                 ans[v[left].second] += end - right + 1;
//                 res.push_back(v[left++]);
//             }
//         }
//         while(left <= mid)  res.push_back(v[left++]);
//         while(right <= end)  res.push_back(v[right++]);
        
//         for(int i = 0; i < res.size(); ++i){
//             v[start + i] = res[i];
//         }
       
        
//     }
    
    
//     void mergeSort(vector<pair<int,int>>&v, int start, int end){
//         if(end == start) return;
        
//         int mid = start + (end - start)/2;
//         mergeSort(v, start, mid);
//         mergeSort(v, mid + 1, end);
//         merge(v, start, mid, end);
        
//     }
    
    
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         vector<pair<int,int>>v(n);
//         ans.resize(n);
//         for(int i = 0; i < n; ++i) v[i] = {nums[i], i};
        
//         mergeSort(v, 0, n - 1);
//         // for(auto x : v) cout<<x.first<<" ";
//         return ans;
//     }
// };
class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while (i <= mid && j <= right) {
            // mind that we're sorting in descending order
            if (v[i].first <= v[j].first) { 
                tmp[k++] = v[j++];
            }
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                count[v[i].second] += right - j + 1;
                tmp[k++] = v[i++];
            }
        }
        while (i <= mid) {
            tmp[k++] = v[i++];
        }
        while (j <= right) {
            tmp[k++] = v[j++];
        }
        for (int i = left; i <= right; i++)
            v[i] = tmp[i-left];
    }        

    void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) {
        if (left >= right) 
            return;

        int mid = left + (right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();

        vector<pair<int, int> > v(N);
        for (int i = 0; i < N; i++)   
            v[i] = make_pair(nums[i], i);

        vector<int> count(N, 0);
        // sorting in descending order
        mergeSort(count, v, 0, N-1);

        return count;
    }
};