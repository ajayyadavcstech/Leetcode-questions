class Solution {
public:
    vector<int> par;
    char parent(char ch){
        if(ch==(par[ch-'a']+'a')) return ch;
        return parent(par[ch-'a']+'a');
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        par.resize(26);
        for(int i=0;i<26;i++) par[i]  = i;
        for(int i=0;i<n;i++){
            char p1 = parent(s1[i]);
            char p2 = parent(s2[i]);
            if(p1<p2) par[p2-'a'] = p1-'a';
            else par[p1-'a'] = p2-'a';
        }
        string ans;
        for(int i=0;i<baseStr.size();i++){
            char p = parent(baseStr[i]);
            ans.push_back(p);
        }
        return ans;
    }
};