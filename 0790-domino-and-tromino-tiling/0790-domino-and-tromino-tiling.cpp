class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;
    long long solve(int i,int j,int n){
        if(j==n || i==n) return 1;
        if(i==j && j==n-1) return 2;
        if(i==n-1 || j==n-1) return 2;
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long total = 0;
        if(i==j){
            total+=solve(i+1,j+1,n); 
            total+=solve(i+2,j+1,n);
            total+=solve(i+1,j+2,n);
            total+=solve(i+2,j+2,n);
        } 
        if(i<j){
            total+=solve(i+2,j+1,n);
            total+=solve(i+2,j,n);
        } 
        if(j<i) {
            total+=solve(i+1,j+2,n);
            total+=solve(i,j+2,n);
        }
        total%=mod;
        return dp[i][j] = total;
    }
    int numTilings(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(1,1,n);
    }
};