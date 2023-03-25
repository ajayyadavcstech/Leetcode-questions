class Solution {
public:
    int solve(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        int node_cnt = 1;
        queue<int> q;
        q.push(node);
        vis[node]++;
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto &x:adj[node]){
                if(!vis[x]){
                    node_cnt++;
                    q.push(x);
                    vis[x]++;
                }
            }
        }
        return node_cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        long long ans = 0;
        long long node_count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long cur_node_count = solve(i,adj,vis);
                ans += node_count*cur_node_count;
                node_count+=cur_node_count;
            }
        }
        return ans;
    }
};