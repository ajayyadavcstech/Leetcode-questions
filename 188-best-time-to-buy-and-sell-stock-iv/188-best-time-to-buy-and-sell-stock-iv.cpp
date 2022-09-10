class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(!prices.size()) return 0;
        vector<vector<int>> dp(prices.size(),vector<int>(k+1,0));
        for(int i=1;i<prices.size();i++){
            for(int j=1;j<=k;j++){
                int mx = dp[i-1][j];
                for(int m=0;m<i;m++){
                    mx = max(mx,dp[m][j-1]+prices[i]-prices[m]);
                }
                dp[i][j] = mx;
            }
        }
        return dp[prices.size()-1][k];
    }
};