class Solution {
public:
    vector<int> visited;
    bool isCycle(unordered_map<int,list<int>>&adj,int val,vector<int>&dfs){
        visited[val]=1;
        dfs[val]=1;
        for(auto i : adj[val]){
            if(dfs[i]) return true;
            if(visited[i]==0){
                 if(isCycle(adj,i,dfs)) return true;
            }
        }
        dfs[val]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        visited.resize(numCourses);
        for(auto i : prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
               vector<int>dfs(numCourses);
               if(isCycle(adj,i,dfs)) return false;
            }
        }
        return true;
    }
};