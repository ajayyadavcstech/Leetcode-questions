class Solution {
public:
    int mod = 1000000007;
    long long solve(long long val,long long pow){
        if(pow==0) return 1;
        
        if(pow%2==0){
            return solve((val*val)%mod,pow/2)%mod;
        }
        else
            return (val*solve((val*val)%mod,pow/2))%mod;
        
    }
    int countGoodNumbers(long long n) {
        // even means 5 options 
        // odd means 4 option 
        
        long long pow = n/2;
        
        long long ans = solve(20,pow);
        
        if(n%2==0){
            return ans;
        }
        return ((5*ans) % mod);
    }
};