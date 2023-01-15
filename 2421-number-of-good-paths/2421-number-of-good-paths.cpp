class Solution {
public:
    vector<int> parent;
    vector<long long> size;
    int leader(int n){
        if(parent[n]==n) return n;
        return leader(parent[n]);
    }
    void merge(int a,int b){
        a = leader(a);
        b = leader(b);
        if(a==b) return ;
        if(size[a]>size[b]) swap(a,b);
        size[b]+=size[a];
        parent[a] = b;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        parent.resize(vals.size());
        size.resize(vals.size(),1);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        map<int,vector<int>> mp;
        for(int i=0;i<vals.size();i++){
            parent[i] = i;
            mp[vals[i]].push_back(i);
        }
        int ans = 0;
        for(auto &[x,v]:mp){
            unordered_map<int,int> par_cnt;
            for(int i=0;i<v.size();i++){
                int node1 = v[i];
                for(int j=0;j<adj[v[i]].size();j++){
                    int node2 = adj[v[i]][j];
                    if(vals[node2]>vals[node1]) continue;
                    merge(node1,node2);
                }
            }
            for(int i=0;i<v.size();i++){
                int p = leader(v[i]);
                ans+=par_cnt[p];
                par_cnt[p]++;
            }
        }
        return ans + vals.size();
    }
};