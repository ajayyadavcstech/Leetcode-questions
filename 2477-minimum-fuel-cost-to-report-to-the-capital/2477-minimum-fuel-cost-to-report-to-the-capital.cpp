class Solution {
public:
    pair<double,long> solve(int node,unordered_map<int,vector<int>>&adj,int seats,int par=-1){
        
        pair<double,long>  p = {1,0};
        for(auto &x:adj[node]){
            if(x==par) continue;
            pair<double,long> child = solve(x,adj,seats,node);
            p.first+=child.first;
            p.second+=child.second;
        }
        p.second+=ceil(p.first/seats);
        return p;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int,vector<int>> adj;
        for(auto &x:roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        pair<double,long> ans = solve(0,adj,seats);
        return ans.second - ceil(ans.first/seats);
    }
};