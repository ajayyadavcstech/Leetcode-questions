class Solution {
public:
    void solve(int node,vector<int>&adj,vector<int>&dis){
        dis[node] = 0;
        while(adj[node]!=-1 && dis[adj[node]]==-1){
            int next = adj[node];
            dis[next] = dis[node]+1;
            node = next;
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis_node1(n,-1),dis_node2(n,-1);
        solve(node1,edges,dis_node1);
        solve(node2,edges,dis_node2);
        int ans = -1;
        int mn = INT32_MAX;
        for(int i=0;i<n;i++){
            if(dis_node1[i]!=-1 && dis_node2[i]!=-1 && max(dis_node1[i],dis_node2[i])<mn){
                ans = i;
                mn = max(dis_node1[i],dis_node2[i]);
            }
        }
        return ans;
    }
};