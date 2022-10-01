class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        dp[n-1]= s[n-1]=='0' ? 0 : 1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0') {
               dp[i]=0;
                continue;
            }
            int single = dp[i+1];
            int Double = 0;
            if(stoi(s.substr(i,2))<=26) Double = dp[i+2];
            dp[i] = single + Double;
        }
        return dp[0];
    }
};