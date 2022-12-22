class Solution {
public:
    vector<int> left,right;
    pair<int,int> upper_left(int node,unordered_map<int,vector<int>>&adj,int up_sum=0,int up_node=0,int par=-1,int sub=0){
        pair<int,int> p={0,0};
        left[node] = up_sum;
        for(auto &x:adj[node]){
            if(x!=par){
                pair<int,int> temp=upper_left(x,adj,up_sum+p.first+up_node+p.second+1,up_node+p.second+1,node,sub+1);
                p.first+=temp.first;
                p.second+=temp.second;
            }
        }
        left[node]-=sub*(sub+1)/2;
        return {p.first+p.second+1,p.second+1};
    }
    pair<int,int> upper_right(int node,unordered_map<int,vector<int>>&adj,int up_sum=0,int up_node=0,int par=-1){
        pair<int,int> p={0,0};
        right[node] = up_sum;
        for(int i=adj[node].size()-1;i>=0;i--){
            int x = adj[node][i];
            if(x!=par){
                pair<int,int> temp=upper_right(x,adj,up_sum+p.first+up_node+p.second+1,up_node+p.second+1,node);
                p.first+=temp.first;
                p.second+=temp.second;
            }
        }
        right[node]+=p.first;
        return {p.first+p.second+1,p.second+1};
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        left.resize(n,0);
        right.resize(n,0);
        upper_left(0,adj);
        upper_right(0,adj);
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i] = left[i]+right[i];
        return ans;
    }
};