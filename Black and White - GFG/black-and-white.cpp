//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    long long ans = 0;
    int mod = 1000000007;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            long long cur = 0;
            if(j+2<=M && i+1<=N) cur++;
            if(j-2>=1 && i+1<=N) cur++;
            if(j+2<=M && i-1>=1) cur++;
            if(j-2>=1 && i-1>=1) cur++;
            if(i+2<=N && j+1<=M) cur++;
            if(i+2<=N && j-1>=1) cur++;
            if(i-2>=1 && j+1<=M) cur++;
            if(i-2>=1 && j-1>=1) cur++;
            cur = N*M - cur -1;
            ans+=(cur);
            ans%=mod;
        }
    }
    return ans;
}