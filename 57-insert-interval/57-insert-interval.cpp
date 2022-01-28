class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); ++i){
            int front = res[res.size() - 1][1];
            int currFront = intervals[i][0];
            
            if(currFront <= front){
                if(res[res.size() - 1][1] < intervals[i][1]){
                    res[res.size() - 1][1] = intervals[i][1];
                }
            }else{
                res.push_back(intervals[i]);
            }
            
        }
        return res;
       
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       intervals.push_back(newInterval);
        return merge(intervals);
       
    }
};