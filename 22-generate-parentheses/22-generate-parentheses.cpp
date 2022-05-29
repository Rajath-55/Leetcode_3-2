class Solution {
public:
    vector<string>ans;
    
    void backtrack(int open, int close, int n, string temp){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        
        if(open < n){
            backtrack(open+1, close, n, temp+'(');
        }
        if(close < open){
            backtrack(open, close + 1, n, temp + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n, "");
        
        return ans;
        
    }
};