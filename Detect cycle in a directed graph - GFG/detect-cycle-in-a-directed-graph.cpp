// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool dfs(int v,vector<int>adj[],vector<int>&visited,vector<int>&dfsvisited){
      visited[v]++;
      dfsvisited[v]++;
      for(auto x : adj[v]){
          if(!visited[x] && dfs(x,adj,visited,dfsvisited)){
              return true;
          }
          else if(visited[x] && dfsvisited[x]){
              return true;
          }
      }
      dfsvisited[v]--;
      return false;
      
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> dfsVisited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,adj,visited,dfsVisited)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends