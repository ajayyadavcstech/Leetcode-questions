class Solution {
public:
    void bfs(int v,unordered_map<int,list<int>> &adj,vector<int> &visited){
        queue<int> q;
        q.push(v);
        visited[v]++;
        
        while(q.size()){
            int front = q.front();
            q.pop();
            for(auto v : adj[front]){
                if(!visited[v]){
                    visited[v]++;
                    q.push(v);
                }
            }
        }
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        bfs(source,adj,visited);
        return visited[destination];
    }
};