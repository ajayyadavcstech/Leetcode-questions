class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9+7;
        long long s = min(a,b);
        long long c = lcm(a,b);
        long long e = c*((long)n);
        long long ans;
        while(s<=e){
            long long mid = s + (e-s)/2;
            long long cnt = mid/a + mid/b -mid/c;
            if(cnt>=n){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans%mod;
    }
};