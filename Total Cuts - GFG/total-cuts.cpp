//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int> mx(N);
        vector<int> mn(N);
        int val = INT32_MIN;
        for(int i=0;i<N;i++){
            val = max(val,A[i]);
            mx[i] = val;
        }
        val = INT32_MAX;
        for(int i=N-1;i>=0;i--){
            mn[i] = val;
            val = min(val,A[i]);
        }
        int cnt = 0;
        for(int i=0;i<N-1;i++){
            if((mx[i]+mn[i])>=K) cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends