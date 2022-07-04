// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> Indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto x : adj[i]){
                Indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(Indegree[i]==0) q.push(i);
        }
        while(q.size()){
            int front = q.front();
            q.pop();
            for(auto x : adj[front]){
                Indegree[x]--;
                if(Indegree[x]==0) q.push(x);
            }
        }
        for(auto x : Indegree){
            if(x!=0) return true;
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