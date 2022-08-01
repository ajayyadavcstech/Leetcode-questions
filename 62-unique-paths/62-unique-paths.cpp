class Solution {
public:
    vector<vector<int>> dp;
    int solve(int m,int n,int i=0,int j=0){
        if(i==m || j==n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = solve(m,n,i+1,j)+solve(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
       dp.resize(m,vector<int>(n,-1));
        return solve(m,n);
    }
};