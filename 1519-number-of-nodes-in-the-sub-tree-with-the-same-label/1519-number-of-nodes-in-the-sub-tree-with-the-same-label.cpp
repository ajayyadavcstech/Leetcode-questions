class Solution {
public:
    vector<int> ans;
    vector<int> solve(int node,unordered_map<int,vector<int>> &adj,string &labels,int par=-1){
        vector<int> cur(26,0);
        cur[labels[node]-'a']++;
        for(auto &x:adj[node]){
            if(x==par) continue;
            vector<int> t = solve(x,adj,labels,node);
            for(int i=0;i<26;i++){
                cur[i]+=t[i];
            }
        }
        ans[node] = cur[labels[node]-'a'];
        return cur;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>> adj;
        ans.resize(n);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        solve(0,adj,labels);
        return ans;
    }
};