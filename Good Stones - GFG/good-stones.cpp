//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool solve(int node,vector<int>&arr,vector<int>&dp,vector<int>&vis){
        if(node<0 || node>=arr.size()) return true;
        if(vis[node] && dp[node]==false) return false;
        if(vis[node]) return true;
        vis[node] = true;
        dp[node] = solve(node+arr[node],arr,dp,vis);
        return dp[node];
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> dp(arr.size(),false);
        vector<int> vis(arr.size(),false);
        for(int i=0;i<arr.size();i++){
            if(vis[i]==false) solve(i,arr,dp,vis);
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(dp[i]) ans++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends