class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int> dis(n,100000);
        queue<vector<int>> q;
        dis[src] = 0;
        q.push({src,0});
        while(k--){
            int size = q.size();
            while(size--){
                vector<int> node = q.front();
                q.pop();
                for(auto &x:adj[node[0]]){
                    int cur_dis = node[1] + x.second;
                    if(cur_dis<dis[x.first]){
                        dis[x.first] = cur_dis;
                        q.push({x.first,cur_dis});
                    }
                }
            }
        }
        while(q.size()){
         vector<int> node = q.front();
            q.pop();
            for(auto &x:adj[node[0]]){
                int cur_dis = node[1] + x.second;
                if(cur_dis<dis[x.first]){
                    dis[x.first] = cur_dis;
                }
            }
        }
       return  dis[dst]==100000 ? -1 : dis[dst];
    }
};