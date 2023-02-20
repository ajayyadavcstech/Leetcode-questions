//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        // code here 
        
        vector<vector<long>> dp(N+1,vector<long>(4,0));
        int mod = 1e9+7;
        dp[1][0] = 0;
        dp[1][1] = 1;
        dp[1][2] = 1;
        dp[1][3] = 1;
        for(int i=2;i<=N;i++){
            dp[i][0] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
            dp[i][1] = (dp[i-1][0]+dp[i-1][2]+dp[i-1][3])%mod;
            dp[i][2] = (dp[i-1][1]+dp[i-1][0]+dp[i-1][3])%mod;
            dp[i][3] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][0])%mod;
        }
        return dp[N][0];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends