class Solution {
public:
    void solve(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        vis[node] = true;
        for(auto &x:adj[node]){
            if(!vis[x]) solve(x,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        vector<int> vis(n,false);
        unordered_map<int,vector<int>> adj;
        for(auto &x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                solve(i,adj,vis);
            }
        }
        return ans-1;
    }
};