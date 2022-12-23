class Solution {
public:
    vector<int> dp;
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(prices.size(),0);
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(prices[i]<prices[j]) dp[i] = max(dp[i],prices[j]-prices[i]+ ((j+2)<n?dp[j+2]:0));
            }
            dp[i] = max(ans,max(dp[i],dp[i+1]));
        }
        return dp[0];
    }
};