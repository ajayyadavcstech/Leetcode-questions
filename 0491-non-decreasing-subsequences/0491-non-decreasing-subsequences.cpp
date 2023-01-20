class Solution {
public:
    set<vector<int>> st;
    vector<int> v;
    void solve(int i,vector<int>&nums){
        if(i==nums.size()) {
            if(v.size()>1) st.insert(v);
            return ;
        }
        
        solve(i+1,nums);
        if(!v.size() || nums[i]>=v.back()){
            v.push_back(nums[i]);
            solve(i+1,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(0,nums);
        return vector<vector<int>>(st.begin(),st.end());
    }
};