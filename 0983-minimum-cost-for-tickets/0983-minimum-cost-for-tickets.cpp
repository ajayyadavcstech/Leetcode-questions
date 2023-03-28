class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        for(int i=0;i<days.size();i++) dp[days[i]]++;
        for(int i=1;i<366;i++){
            if(dp[i]==0) dp[i] = dp[i-1];
            else{
                int oneday = costs[0] + dp[i-1];
                int sevenday = costs[1] + (i-7>0 ? dp[i-7] : 0);
                int thirtyday =costs[2] + (i-30>0 ? dp[i-30] : 0);
                dp[i] = min({oneday,sevenday,thirtyday});
            }
        }
        return dp[365];
    }
};