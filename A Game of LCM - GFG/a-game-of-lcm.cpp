//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long solve(int n){
      long long ans = n;
      int cnt=0;
      for(long long i=n-1;i>=1;i--){
          if(__gcd(i,ans)==1){
              ans*=i;
              cnt++;
          }
          if(cnt==3) break;
      }
      return ans;
  }
    long long maxGcd(int N) {
        // code here
        return max(solve(N),solve(N-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends