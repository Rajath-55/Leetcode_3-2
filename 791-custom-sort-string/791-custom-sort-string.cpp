class Solution {
public:
    static bool cmp(pair<char,int> &p1,pair<char,int> &p2)
    {
        return p1.second < p2.second;
    }
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i;
        }
        vector<pair<char,int>> v2;
        for(int i=0;i<s.size()&&order.size();i++)
        {
            v2.push_back(make_pair(s[i],mp[s[i]]));
        }
        sort(v2.begin(),v2.end(),cmp);
        string ans="";
        for(auto x:v2)
        {
            ans+=x.first;
        }
        return ans;
    }
};