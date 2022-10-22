//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 100000000;
  long solve(int N,vector<int>&dp){
      if(N==0 || N==1) return 1;
      if(dp[N]!=-1) return dp[N];
      return dp[N] = (solve(N-1,dp) + solve(N-2,dp))%mod;
  }
    int fillingBucket(int N) {
        vector<int> dp(N+1,-1);
        // code here
        return solve(N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends