class Solution {
public:
    void CountReorderRoad(int node,unordered_map<int,vector<vector<int>>>&adj,int par,int &ans){
        for(auto &x:adj[node]){
            if(x[0]==par) continue;
            if(x[1]==1) ans++;
            CountReorderRoad(x[0],adj,node,ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& list) {
        unordered_map<int,vector<vector<int>>> adj;
        for(auto &x:list){
            adj[x[0]].push_back({x[1],1});
            adj[x[1]].push_back({x[0],-1});
        }
        int ans = 0;
        CountReorderRoad(0,adj,-1,ans);
        return ans;
    }
};