class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {};
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
               if(j==0)dp[i][j]=1;
                else{
                   for(int p = 0 ; p<=min(i-1,j);p++){
                            dp[i][j] = (dp[i][j]+dp[i-1][j-p])%1000000007;
                    }
                }
            }
        }
        return dp[n][k];
    }
};
// class Solution {
// public:
//     int dp[1001][1001];
//     int kInversePairs(int n, int k) {
//         if(k==0) return 1;
//         if(n==0) return 0;
//         if(dp[n][k]!=NULL) return dp[n][k]; 
//         int count = 0;
//         for(int i=0;i<=k && n-1>=i;i++){
//             count=(count+kInversePairs(n-1,k-i))%1000000007;
//         }
//         return dp[n][k] = count;
//     }
// };