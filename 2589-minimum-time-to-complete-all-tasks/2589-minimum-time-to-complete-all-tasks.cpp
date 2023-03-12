class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        vector<int> dp(2001,0);
        int ans = 0;
        sort(tasks.begin(),tasks.end(),comp);
        for(auto &x:tasks){
            int l = x[0];
            int r = x[1];
            int d = x[2];
            for(int i=l;i<=r;i++){
                if(dp[i]) d--;
            }
            for(int i=r;i>=l;i--){
                if(d<=0) break;
                if(dp[i]) continue;
                d--;
                ans++;
                dp[i] = 1;
            }
        }
        return ans;
    }
};