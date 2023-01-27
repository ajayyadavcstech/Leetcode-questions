class Solution {
public:
    unordered_set<string> st;
    bool solve(int ind,string &s){
        if(ind==s.size()) return false;
        
        string str;
        for(int i = ind;i<s.size();i++){
            str.push_back(s[i]);
            if(st.count(str) && (st.count(s.substr(i+1,s.size()-i-1))  || solve(i+1,s))) return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for(auto &x:words) st.insert(x);
        for(auto &x:words) if(solve(0,x)) ans.push_back(x);
        return ans;
    }
};