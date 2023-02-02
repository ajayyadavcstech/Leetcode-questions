//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  void solve(int node,vector<int>&adj,vector<int>&vis,int &mx){
      if(vis[node]!=0) return;
      int temp = node;
      while(temp!=-1 && vis[temp]==0){
          vis[temp] = 1;
          temp = adj[temp];
      }
      if(temp!=-1 && vis[temp]==1){
          int t = adj[temp];
          int sum = 0;
          while(t!=temp){
              sum+=t;
              t = adj[t];
          }
          sum+=temp;
          mx = max(sum,mx);
      }
      temp = node;
      while(temp!=-1 && vis[temp]==1){
          vis[temp] = 2;
          temp = adj[temp];
      }
  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    vector<int> vis(N,0);
    int mx = -1;
    for(int i=0;i<N;i++){
        solve(i,Edge,vis,mx);
    }
    return mx;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends