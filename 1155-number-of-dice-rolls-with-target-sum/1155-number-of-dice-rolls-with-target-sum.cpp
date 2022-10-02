class Solution {
public:
    int mod = 1000000007;
    vector<vector<int>> dp;
    int solve(int n,int k,int target,int cur_sum){
        if(n==0) return cur_sum==target ? 1 : 0;
        if(cur_sum>target) return 0;
        if(dp[n][cur_sum]!=-1) return dp[n][cur_sum];
        long cur = 0;
        for(int i=1;i<=k;i++){
            cur +=solve(n-1,k,target,cur_sum+i);
            cur = cur%mod;
        }
        return dp[n][cur_sum] = cur;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,0);
    }
};