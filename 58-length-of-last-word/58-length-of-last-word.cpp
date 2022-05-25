class Solution {
public:
    int lengthOfLastWord(string s) {
        
        while(s.back() == ' ') s.pop_back();
        stringstream ss(s);
        
        string temp;
        
        while(getline(ss, temp, ' ')){
            
        }
        cout<<temp<<"\n";
        return temp.size();
    }
};