class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&nums,int target,int cur=0){
        if(cur==target) return 1;
        if(dp[cur]!=-1) return dp[cur];
        dp[cur] = 0;
        for(auto x : nums){
            if(x + cur <= target) dp[cur]+=solve(nums,target,cur+x);
        }
        return dp[cur];
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        sort(nums.begin(),nums.end());
        return solve(nums,target);
    }
};