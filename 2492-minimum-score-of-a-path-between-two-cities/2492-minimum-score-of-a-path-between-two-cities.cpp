class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<vector<int>>> adj;
        for(auto &v:roads){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        int mn = INT32_MAX;
        vector<int> vis(n+1,false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto &x:adj[node]){
                mn = min(mn,x[1]);
                if(!vis[x[0]]){
                    vis[x[0]] = true;
                    q.push(x[0]);
                }
            }
        }
        return mn;
    }
};