class Solution {
    void nextpermut(string &s)
    {
        int i = s.size()-1;
        int k,l;
        //find first element less than its next from the last
        for(k=s.size()-2;k>=0;k--)
        {
            if(s[k]<s[k+1]) break;
        }
        if (k < 0) return ;
        
        //find first element which is greater than the element found from the last
        for(l=s.size()-1;l>k;l--)
        {
            if(s[k]<s[l]) break;
        }
        swap(s[k], s[l]);
        reverse(s.begin()+k+1, s.end());
        
    }
public:
    int getMinSwaps(string num, int k) {
        
        string s=num;        
        while(k--)
        {
            nextpermut(s);
        }
        int count=0;
        int i=0,j=0;
        while(i<num.size() and j<num.size())
        {
            if(num[i]!=s[i])
            {
                int c=j;
                //finding element where can we perform swap
                while(s[c]!=num[i] and c<num.size())
                {
                    c++;
                    count++;
                }
                //making the swaps 
                while(c!=j) {
                    swap(s[c],s[c-1]);
                    c--;
                }
                
            }
            i++;
            j++;
        }
        
        return count;
        
    }
};