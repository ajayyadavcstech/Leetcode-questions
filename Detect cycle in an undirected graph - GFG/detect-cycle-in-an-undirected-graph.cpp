// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int v,vector<int> adj[],vector<int>&visited){
        queue<pair<int,int>> q;
        q.push(make_pair(v,-1));
        visited[v]++;
        while(q.size()){
            pair<int,int> front = q.front();
            q.pop();
            for(auto x : adj[front.first]){
                if(x==front.second) continue;
                if(visited[x]) return true;
                visited[x]++;
                q.push(make_pair(x,front.first));
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                bool isCycle = bfs(i,adj,visited);
                if(isCycle) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends