class Solution {
public:
    vector<int> dp;
    int solve(string &s,int i){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        
        if(s[i]=='0') return 0;
        if(s[i]=='1') {
            return dp[i] = (i<s.size()-1) ? (solve(s,i+1)+solve(s,i+2)) : solve(s,i+1);
        }
        if(s[i]=='2'){
            return dp[i] = (i<s.size()-1 && s[i+1]>='0' && s[i+1]<='6') ? (solve(s,i+1)+solve(s,i+2)) : solve(s,i+1);
        }
        
        return dp[i] = solve(s,i+1);
    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return solve(s,0);
    }
};