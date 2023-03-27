class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int top = i-1>=0 ? dp[i-1][j] : INT32_MAX;
                int left = j-1>=0 ? dp[i][j-1] : INT32_MAX;
                dp[i][j] = min(top,left) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};