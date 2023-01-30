//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(int node,unordered_map<int,vector<int>> &adj,int &total_camera,int par){
      
      int need = 0;
      int camera = 0;
      for(auto &x:adj[node]){
          if(x==par) continue;
          int num = solve(x,adj,total_camera,node);
          if(num==0) need++;
          else if(num==1) camera++;
      }
      if(need){
          total_camera++;
          return 1;
      }
     return 0;
      
  }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        unordered_map<int,vector<int>> adj;
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int total_camera = 0;
        return solve(1,adj,total_camera,-1)==-1 ? total_camera+1 : total_camera;
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
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends