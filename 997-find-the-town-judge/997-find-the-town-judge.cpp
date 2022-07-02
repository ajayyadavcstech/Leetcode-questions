class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,list<int>> adj;
        for(auto x : trust){
            adj[x[0]].push_back(x[1]);
        }
        int judge = 0;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0) {
                judge = i;
            }
        }
        if(judge==0) return -1;
        for(int i=1;i<=n;i++){
            if(find(adj[i].begin(),adj[i].end(),judge)==adj[i].end() && i!=judge){
                return -1;
            }
        }
        return judge;
    }
};