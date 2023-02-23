//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<long>> dp(n,vector<long>(m,0));
        int mod = 1e9+7;
        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || (i==0 && j==0)) continue;
                if(i==0) dp[i][j] = dp[i][j-1];
                else dp[i][j] = ((i-1>=0) ? dp[i-1][j] : 0) + ((j-1>=0) ? dp[i][j-1] : 0);
                dp[i][j]%=mod;
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends