//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        int cnt = 0;
        long long sum = 0;
        int mn = INT32_MAX;
        for(int i=0;i<N;i++){
            if(B[i]&1) B[i]--;
            cnt+=B[i];
            sum+=B[i]*A[i];
            if(B[i]) mn = min(mn,A[i]);
        }
        if(cnt%4) sum-=mn*2;
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends