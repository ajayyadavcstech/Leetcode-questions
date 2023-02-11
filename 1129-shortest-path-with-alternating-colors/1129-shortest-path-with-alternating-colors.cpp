class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,vector<int>> blueAdj,redAdj;
        vector<vector<int>> vis(n,vector<int>(2,false));
        for(auto &x:redEdges){
            redAdj[x[0]].push_back(x[1]);
        }
        for(auto &x:blueEdges){
            blueAdj[x[0]].push_back(x[1]);
        }
        vector<int> ans(n,-1);
        ans[0] = 0;
        queue<vector<int>> q;
        vis[0][0] = true;
        vis[0][1] = true;
        q.push({0,0});
        q.push({0,1});
        int stp = 0;
        while(q.size()){
            int size = q.size();
            stp++;
            while(size--){
                int node = q.front()[0];
                int pre = q.front()[1];
                q.pop();
                
                unordered_map<int,vector<int>> &Adj = (pre==0 ? blueAdj : redAdj);
                for(auto &x:Adj[node]){
                    if(vis[x][1-pre]==false){
                        vis[x][1-pre] = true;
                        if(ans[x]==-1) ans[x] = stp;
                        q.push({x,1-pre});
                    }
                }
            }
        }
        return ans;
    }
};