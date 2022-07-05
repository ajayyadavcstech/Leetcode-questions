class Solution {
public:
    bool dfs(int v,vector<vector<int>> &adj,vector<int>&dfsvisited,vector<int> &visited,vector<int>&ans,vector<int>&isCircle){
        visited[v]++;
        dfsvisited[v]++;
        bool isCycle = false;
        for(auto x : adj[v]){
            if(visited[x] && !dfsvisited[x]){
                if(isCircle[x]){
                    isCycle = true;
                }
            }
            else if(!visited[x]){
                if(dfs(x,adj,dfsvisited,visited,ans,isCircle))
                    isCycle = true;
            }
            else if(dfsvisited[x]){
                isCycle = true;
            }
        }
        dfsvisited[v]--;
        if(!isCycle){
            ans.push_back(v);
            return false;
        }
        isCircle[v] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),0);
        vector<int> dfsvisited(graph.size(),0);
        vector<int> isCircle(graph.size(),0);
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                dfs(i,graph,dfsvisited,visited,ans,isCircle);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};