class Solution {
public:
    vector<int> v;
    set<vector<int>> st;
    void solve(vector<int>&nums,int ind){
        if(ind==nums.size()){
            st.insert(v);
            return ;
        }
        solve(nums,ind+1);
        v.push_back(nums[ind]);
        solve(nums,ind+1);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        vector<vector<int>> v(st.begin(),st.end());
        return v;
    }
};