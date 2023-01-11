class Solution {
public:
    pair<int,int> solve(int node,unordered_map<int,vector<int>>&adj,vector<bool>&hasApple,int par){
        pair<int,int> cur = {0,0};
        for(auto &x:adj[node]){
            if(x!=par) {
                pair<int,int> t =solve(x,adj,hasApple,node);
                cur.first+=t.first;
                cur.second+=t.second;
            }
        }
        if(hasApple[node]) cur.first++;
        if(cur.first>0) cur.second+=2;
        return cur;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        pair<int,int> ans = solve(0,adj,hasApple,-1);
        return ans.first>0 ? ans.second-2 : 0;
    }
};