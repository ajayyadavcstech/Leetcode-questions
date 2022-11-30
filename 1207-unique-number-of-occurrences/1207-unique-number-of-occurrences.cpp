class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(auto &x:arr) mp[x]++;
        for(auto &x:mp) st.insert(x.second);
        return mp.size()==st.size();
    }
};