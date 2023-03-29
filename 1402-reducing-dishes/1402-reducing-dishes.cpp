class Solution {
public:
    vector<vector<int>> dp;
    int solve(int time,int i,vector<int>&sat){
        if(i==sat.size()) return 0;
        if(dp[time][i]!=-1) return dp[time][i];
        return dp[time][i] = max(time*sat[i]+solve(time+1,i+1,sat),solve(time,i+1,sat));
    }
    int maxSatisfaction(vector<int>& sat) {
        dp.resize(sat.size()+1,vector<int>(sat.size()+1,-1));
        sort(sat.begin(),sat.end());
        return solve(1,0,sat);
    }
};