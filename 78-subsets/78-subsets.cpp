class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void solve(vector<int>&nums,int ind){
        if(ind==nums.size()){
            ans.push_back(v);
            return ;
        }
        
        v.push_back(nums[ind]);
        solve(nums,ind+1);
        v.pop_back();
        
        solve(nums,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};