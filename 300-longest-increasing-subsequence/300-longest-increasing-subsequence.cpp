class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        for(int i=1;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int mx = 0;
        for(auto x : dp) mx = max(mx,x);
        return mx;
    }
};