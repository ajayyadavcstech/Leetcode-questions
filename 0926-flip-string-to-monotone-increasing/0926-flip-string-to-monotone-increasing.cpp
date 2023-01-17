class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i][0] = min(dp[i+1][0],1+dp[i+1][1]);
                dp[i][1] = 1 + dp[i+1][1];
            }
            else{
                dp[i][0] = min(dp[i+1][1],1+dp[i+1][0]);
                dp[i][1] = dp[i+1][1];
            }
        }
        return dp[0][0];
    }
};