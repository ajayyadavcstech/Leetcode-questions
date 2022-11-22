class Solution {
public:
    vector<int> sqr;
    vector<vector<int>> dp;
    long long solve(int n,int i){
        if(n==0) return 0;
        if(i<0) return INT32_MAX;
        if(dp[n][i]!=-1) return dp[n][i];
        long long cnt = 0;
        cnt = solve(n,i-1);
        cnt = min(cnt,n/sqr[i]+solve(n%sqr[i],i-1));
        return dp[n][i] = cnt;
    }
    int numSquares(int n) {
        for(int i = 1;i*i<=n;i++) sqr.push_back(i*i);
        dp.resize(n+1,vector<int>(sqr.size()+1,-1));
        return solve(n,sqr.size()-1);
    }
};