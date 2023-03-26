class Solution {
public:
    int solve(int node,vector<int>&edges,vector<int>&vis){
        int n = vis.size();
        unordered_set<int> cur_vis;
        int i = node;
        int cnt = 0;
        while(i!=-1 && !vis[i]){
            cnt++;
            vis[i]++;
            cur_vis.insert(i);
            i = edges[i];
        }
        if(i==-1 || !cur_vis.count(i)) return -1;
        while(node!=i){
            cnt--;
            node = edges[node];
        }
        return cnt;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);
        int ans = -1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans = max(ans,solve(i,edges,vis));
            }
        }
        return ans;
    }
};