class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        return v1[0]<v2[0];
    }
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        multiset<int> st;
        for(auto &x:intervals){
            auto pt = st.lower_bound(x[0]);
            if(pt==st.begin()) st.insert(x[1]);
            else{
                pt--;
                st.erase(pt);
                st.insert(x[1]);
            }
        }
        return st.size();
    }
};