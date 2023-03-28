class Solution {
public:
    vector<int> dp;
    int solve(int d,vector<int>& visite,vector<int>&costs){
        if(d>365) return 0;
        if(dp[d]!=-1) return dp[d];
        
        if(visite[d]==false) return solve(d+1,visite,costs);
        return dp[d] = min({costs[0]+solve(d+1,visite,costs),costs[1]+solve(d+7,visite,costs),costs[2]+solve(d+30,visite,costs)});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> visited(366,0);
        dp.resize(366,-1);
        for(auto &x:days) visited[x]++;
        return solve(days[0],visited,costs);
    }
};