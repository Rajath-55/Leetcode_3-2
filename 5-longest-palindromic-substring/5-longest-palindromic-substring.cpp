class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        string maxi = "";
        
        for(int i = 0; i < n; ++i){
            int start = i, end = i;
            while(start >= 0 and end < n and s[start] == s[end]){
                start--;
                end++;
            }
            cout<<start<<" "<<end<<"\n";
            start++;
            end--;
            string temp = s.substr(start, end - start + 1);
            if(maxi.size() < temp.size()) maxi = temp;
            start = i; end = i + 1;
            while(start >= 0 and end < n and s[start] == s[end]){
                start--;
                end++;
            }
            cout<<start<<" "<<end<<"\n";
            start++;
            end--;
            temp = s.substr(start, end - start + 1);
            if(maxi.size() < temp.size()) maxi = temp;
            
        }
        return maxi;
        
        
    }
};