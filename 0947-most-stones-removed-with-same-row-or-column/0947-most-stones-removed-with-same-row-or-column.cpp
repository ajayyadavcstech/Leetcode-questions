class Solution {
public:
    map<vector<int>,vector<vector<int>>> edg;
    map<vector<int>,int> visited;
    int solve(vector<int> cur){
        if(visited[cur]==1) return 0;
        visited[cur] = 1;
        int cnt = 0;
        for(auto &x : edg[cur]){
            cnt+=(solve(x));
        }
        return 1+cnt;
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> row,col;
        for(auto &v:stones){
            visited[v] = 0;
            if(row.count(v[0])){
                vector<int> temp = {v[0],row[v[0]]};
                edg[temp].push_back(v);
                edg[v].push_back(temp);
            }
            if(col.count(v[1])){
                vector<int> temp = {col[v[1]],v[1]};
                edg[temp].push_back(v);
                edg[v].push_back(temp);
            }
            row[v[0]] = v[1];
            col[v[1]] = v[0];
        }
        int ans = 0;
        for(auto &x : stones){
            if(visited[x]==0) ans+=(solve(x)-1);
        }
        return ans;
    }
};