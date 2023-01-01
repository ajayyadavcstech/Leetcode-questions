class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> v;
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                v.push_back(str);
                str = "";
            }
            else str.push_back(s[i]);
        }
        v.push_back(str);
        if(v.size()!=p.size()) return false;
        unordered_map<char,string> mp;
        unordered_set<string> st;
        for(int i=0;i<p.size();i++){
            if(mp.count(p[i]) && mp[p[i]]!=v[i]) return false;
            if(mp.count(p[i])==0 && st.count(v[i])) return false;
            mp[p[i]] = v[i];
            st.insert(v[i]);
        }
        return true;
    }
};