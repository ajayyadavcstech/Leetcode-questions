class Solution {
public:
    vector<vector<int>> dp;
    int diff;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = multipliers.size();
        int m = nums.size();
        dp.resize(multipliers.size(),vector<int>(multipliers.size(),-1));
        diff = nums.size() - multipliers.size();
        for(int i = n-1 ;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i>j){
                    dp[i][j] = 0;
                    continue;
                }
                int option_1 = nums[i]*multipliers[i+m-j-1-diff] + (i+1==n ? 0 : dp[i+1][j]);
                int option_2 = nums[j+diff]*multipliers[i+m-j-1-diff] + (j-1==-1 ? 0 : dp[i][j-1]);
                dp[i][j] = max(option_1,option_2);
            }
        }
        
        return dp[0][n-1];
    }
};