//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void solve(long long &x,long long cur,long long &ans){
      if(cur>x) return ;
      ans = max(ans,cur);
      int rem = cur%10;
      if(rem!=9)solve(x,cur*10+(rem+1),ans);
      if(rem!=0)solve(x,cur*10+(rem-1),ans);
  }
    long long jumpingNums(long long X) {
        // code here
        long long ans = 0;
        for(int i=1;i<=9;i++) solve(X,i,ans);
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends