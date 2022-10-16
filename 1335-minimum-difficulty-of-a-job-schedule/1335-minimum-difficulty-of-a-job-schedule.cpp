class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& job,int d,int ind){
        if(ind==job.size()) return 0;
        if(d==0) return 10000;
        if(dp[ind][d]!=-1) return dp[ind][d];
        
        int num = INT32_MIN;
        int mn = INT32_MAX;
        for(int i=ind;i<(job.size()-d+1);i++){
            num = max(num,job[i]);
            int val = num+solve(job,d-1,i+1);
            mn = min(mn,val);
        }
        return dp[ind][d]=mn;
    }
    int minDifficulty(vector<int>& job, int d) {
        if(job.size()<d) return -1;
        dp.resize(job.size(),vector<int>(d+1,-1));
        return solve(job,d,0);
    }
};