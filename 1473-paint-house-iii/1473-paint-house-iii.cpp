class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>&houses,vector<vector<int>>&cost,int pre,int cur,int n,int &target,int group){
        if(cur==houses.size()){
            if(group!=target) return -1;
            return 0;
        }
        if(dp[pre][cur][group]!=-2) return dp[pre][cur][group];
        int MinCost = INT32_MAX;
        if(houses[cur]!=0){
            if(houses[cur]!=pre) group++;
            if(group>target) {
                    group--;
                    return -1;
                }
            MinCost = solve(houses,cost,houses[cur],cur+1,n,target,group);
            if(houses[cur]!=pre) group--;
            return dp[pre][cur][group] = MinCost;
        }
        else{
            for(int i=0;i<n;i++){
                if(i+1!=pre) group++;
                if(group>target) {
                    group--;
                    continue;
                }
                int Cost = solve(houses,cost,i+1,cur+1,n,target,group);
                if(Cost!=-1) MinCost = min(MinCost,cost[cur][i] + Cost);
                if(i+1!=pre) group--;
            }
            return dp[pre][cur][group] =  (MinCost == INT32_MAX ? -1 : MinCost);
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp.resize(21,vector<vector<int>>(m+1,vector<int>(m+1,-2)));
        return solve(houses,cost,0,0,n,target,0);
    }
};