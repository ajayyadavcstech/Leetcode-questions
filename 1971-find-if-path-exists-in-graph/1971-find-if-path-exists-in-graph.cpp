class Solution {
public:
    int par(int a,vector<int>&parent){
        if(parent[a]==a) return a;
        return par(parent[a],parent);
    }
    void add(int a,int b,vector<int>&parent){
        int p1 = par(a,parent);
        int p2 = par(b,parent);
        parent[p2] = p1;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i] = i;
        for(auto &v:edges){
            add(v[0],v[1],parent);
        }
        int p1 = par(source,parent);
        int p2 = par(destination,parent);
        return p1==p2;
    }
};