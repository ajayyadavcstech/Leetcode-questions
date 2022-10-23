class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;
        for(auto &x:nums){
            if(st.count(x)) {
                ans.push_back(x);
            }
            st.insert(x);
        }
        for(int i=1;i<=nums.size();i++) {
            if(st.count(i)==0) ans.push_back(i);
        }
        return ans;
    }
};