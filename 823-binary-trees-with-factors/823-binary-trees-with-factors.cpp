class Solution {
public:
    int mod = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<long> dp(arr.size(),1);
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            int s = 0;
            int e = i-1;
            while(s<=e){
                long mul = (long)arr[s]*arr[e];
                if(mul==arr[i]){
                    long cnt = (dp[s]*dp[e]) %mod;
                    if(s!=e) cnt*=2;
                    dp[i]= (dp[i]+cnt)%mod;
                    e--;
                    s++;
                }
                else if(mul>arr[i]) e--;
                else s++;
            }
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};