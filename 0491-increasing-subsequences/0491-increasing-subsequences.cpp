class Solution {
public:
    set<vector<int>> st;
    vector<int> v;
    void solve(vector<int>&nums,int pre,int ind){
        if(ind==nums.size()){
            if(v.size()>=2) st.insert(v);
            return ;
        }
        
        solve(nums,pre,ind+1);
        v.push_back(nums[ind]);
        if(nums[ind]>=pre) solve(nums,nums[ind],ind+1);
        v.pop_back();
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,-200,0);
        vector<vector<int>> ans;
        for(auto &x : st) ans.push_back(x);
        return ans;
    }
};