class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string temp = countAndSay(n-1);
        string res = "";
        // cout<<temp.length()<<"\n";
        for(int i = 0; i < temp.length(); ++i){
            int count = 1;
            char t = temp[i];
            while(i < temp.length() - 1 and temp[i] == temp[i+1]){
                count++;
                i++;
            }
            res += to_string(count);
            res+= t;
        }
        return res;
    }
};