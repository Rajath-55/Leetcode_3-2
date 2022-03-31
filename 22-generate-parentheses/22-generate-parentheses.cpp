class Solution {
public:
    vector<string>ans;
    int n;
    void recurse(int open, int close, string temp){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            recurse(open + 1, close, temp + '(');
        }
        if(close < open){
            recurse(open, close + 1, temp + ')');
        }
        return;
        
        
    }
    vector<string> generateParenthesis(int n) {
        // open bracket add, recurse, close bracket add, recurse;
      
        this->n = n;
        recurse(0,0,"");
        return ans;
    }
};