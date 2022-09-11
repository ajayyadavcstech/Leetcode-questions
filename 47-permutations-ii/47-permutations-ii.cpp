class Solution {
public:
    vector<int> visited;
    vector<int> v;
    vector<vector<int>> ans;
    void solve(vector<int>&nums){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(!visited[i] && st.find(nums[i])==st.end()){
                visited[i]++;
                st.insert(nums[i]);
            v.push_back(nums[i]);
                solve(nums);
                visited[i]--;
                v.pop_back();

            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size(),0);
        solve(nums);
        return ans;
    }
};