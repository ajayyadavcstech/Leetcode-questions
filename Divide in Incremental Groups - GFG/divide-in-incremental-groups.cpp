//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solve(int n,int k,vector<vector<vector<int>>>&dp,int pre){
      if(k==0 && n==0) return 1;
      if(k==0) return 0;
      if(dp[pre][n][k]!=-1) return dp[pre][n][k];
      
      if(pre>n) return 0;
      int cnt = 0;
      for(int i=pre;i<=n;i++){
          cnt+=solve(n-i,k-1,dp,i);
      }
      return dp[pre][n][k] = cnt;
  }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));
        return solve(N,K,dp,1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends