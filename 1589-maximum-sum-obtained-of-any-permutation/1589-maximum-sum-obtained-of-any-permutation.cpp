class Solution {
public:
    int mod = 1000000007;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for(auto &v:req){
            dp[v[0]]++;
            dp[v[1]+1]--;
        }
        int sum = 0;
        for(int i=0;i<=n;i++){
            sum+=dp[i];
            dp[i] = sum;
        }
        long long ans = 0;
        sort(dp.begin(),dp.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<n;i++){
            ans= (ans + ((long)nums[i]*dp[i]))%mod;
        }
        return ans;
    }
};