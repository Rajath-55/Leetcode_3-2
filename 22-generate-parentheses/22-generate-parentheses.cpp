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
            open++;
            temp+='(';
            recurse(open, close, temp);
            open--;
            temp.pop_back();
        }
        if(close < open){
            close++;
            temp+=')';
            recurse(open, close , temp);
            close--;
            temp.pop_back();
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