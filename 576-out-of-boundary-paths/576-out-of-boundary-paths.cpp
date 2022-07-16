class Solution {
public:
    vector<vector<vector<int>>> dp;
    long long solve(int row, int col, int maxMove, int i, int j) {
       if(i<0 || i==row || j<0 || j==col) return 1;
        if(maxMove==0) return 0;
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
        return dp[i][j][maxMove] = (solve(row,col,maxMove-1,i,j+1) + solve(row,col,maxMove-1,i,j-1) + solve(row,col,maxMove-1,i+1,j) + solve(row,col,maxMove-1,i-1,j))%1000000007; 
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(50,vector<vector<int>>(50,vector<int>(51,-1)));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};