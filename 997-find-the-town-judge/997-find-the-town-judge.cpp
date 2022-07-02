class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> Indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        for(auto x : trust){
            outdegree[x[0]]++;
            Indegree[x[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(outdegree[i]==0 && Indegree[i]==n-1) return i;
        }
        return -1;
    }
};