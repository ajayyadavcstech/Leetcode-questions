class Solution {
public:
    set<vector<int>> st;
    vector<int> v;
    void solve(int i,vector<int>&nums,int pre=INT32_MIN){
        if(v.size()>1) st.insert(v);
        if(i==nums.size()) return ;
        
        if(nums[i]<pre)  solve(i+1,nums,pre);
        else{
            solve(i+1,nums,pre);
            v.push_back(nums[i]);
            solve(i+1,nums,nums[i]);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(0,nums);
        return vector<vector<int>>(st.begin(),st.end());
    }
};