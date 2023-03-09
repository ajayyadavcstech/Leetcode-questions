class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dp(n+1,false);
        for(int i=2;i*i<=n;i++){
            if(dp[i]) continue;
            for(int j=i*i;j<=n;j+=i){
                dp[j] = true;
            }
        }
        int cnt = 0;
        for(int i=2;i<n;i++) if(dp[i]==false) cnt++;
        return cnt;
    }
};