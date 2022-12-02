class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_set<int> st;
        for(auto &x:word1) st.insert(x);
        for(auto &x:word2) st.erase(x);
        if(st.size()) return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0;i<word1.size();i++){
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};