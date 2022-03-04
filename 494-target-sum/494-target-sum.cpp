class Solution {
public:
    int c=0;
    void func(vector<int>&n,int t,int i)
    {
      if(i>=n.size())
      {if(t==0)
          c++;return;}
      func(n,t+n[i],i+1);
      func(n,t-n[i],i+1);  
    }
    int findTargetSumWays(vector<int>&n, int target) {
        func(n,target,0);
        return c;
    }
    
};