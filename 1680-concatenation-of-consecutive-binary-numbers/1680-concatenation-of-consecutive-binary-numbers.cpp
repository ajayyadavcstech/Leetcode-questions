class Solution {
public:
    int mod = 1000000007;
    int concatenatedBinary(int n) {
        long ans = 0;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(2147483648%i==0) cnt++;
            ans = ans<<cnt;
            ans = ans|i;
            ans = ans%mod;
        }
        return ans;
    }
};