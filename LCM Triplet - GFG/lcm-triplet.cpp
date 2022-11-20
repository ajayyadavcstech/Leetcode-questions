//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long lcm(long long a,long long b){
      return a*b/__gcd(a,b);
  }
    long long lcmTriplets(long long N) {
        // code here
        if(N<3) return N;
        if(!(N&1)) return max(lcm(N,lcm(N-1,N-3)),lcm(N-1,lcm(N-2,N-3)));
        return lcm(N,lcm(N-1,N-2));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends