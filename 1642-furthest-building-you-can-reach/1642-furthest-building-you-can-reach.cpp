class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int idx;
        
        for(idx = 1; idx < heights.size(); ++idx){
            if(heights[idx] - heights[idx-1] <= 0) continue;
            bricks -= heights[idx] - heights[idx-1];
            pq.push(heights[idx] - heights[idx-1]);
            if(bricks < 0){
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            if(ladders < 0) break;
        }
        return --idx;
    }
};