class Solution {
public:
    
    bool isIntersection(int oneX, int oneY, int twoX, int twoY){
        return ((oneY >= twoX and oneX <= twoY) or (twoX >= oneX and twoX <= oneY));
    }
    
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
      vector<vector<int>> res;
        int n=firstList.size();
        int m=secondList.size();
        
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(firstList[i][1]>=secondList[j][0] && firstList[i][0]<=secondList[j][1] ||
               secondList[j][0]<=firstList[i][1] && secondList[j][1]>=firstList[i][0]){//intersection is present
                int s=max(firstList[i][0],secondList[j][0]);
                int l=min(firstList[i][1],secondList[j][1]);
                res.push_back({s,l});
            }

                if(firstList[i][1]<secondList[j][1])
                    i++;
                else
                    j++;
        }
        
        
       
       
        
        return res;
        
    }
};