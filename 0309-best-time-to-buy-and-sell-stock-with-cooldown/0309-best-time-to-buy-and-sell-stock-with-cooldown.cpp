class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&prices,int ind){
        if(ind>=prices.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mx = 0;
        for(int i=ind+1;i<prices.size();i++){
            if(prices[i]>prices[ind]) mx = max(mx,prices[i]-prices[ind]+solve(prices,i+2));
        }
        return dp[ind] = max(mx,solve(prices,ind+1));
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),-1);
        return solve(prices,0);
    }
};