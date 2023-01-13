class Solution {
public:
    int ans = 0;
    pair<int,char> solve(int node,unordered_map<int,vector<int>>&adj,string &s){
        int path_1 = 0;
        int path_2 = 0;
        for(auto &x:adj[node]){
            pair<int,char> p = solve(x,adj,s);
            if(s[node]!=p.second){
                if(p.first>path_1){
                    path_2 = path_1;
                    path_1 = p.first;
                }
                else{
                    path_2 = max(path_2,p.first);
                }
            }
        }
        int cur_mx = path_1+path_2+1;
        ans = max(ans,cur_mx);
        return {max(path_1,path_2)+1,s[node]};
    }
    int longestPath(vector<int>& p, string s) {
        unordered_map<int,vector<int>> adj;
        for(int i=1;i<p.size();i++){
            adj[p[i]].push_back(i);
        }
        solve(0,adj,s);
        return ans;
    }
};