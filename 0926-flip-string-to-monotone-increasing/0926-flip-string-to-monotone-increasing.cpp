class Solution {
public:
    vector<vector<int>> dp;
    int solve(string&s,int ind,char pre){
        if(ind==s.size()) return 0;
        if(dp[ind][pre-'0']!=-1) return dp[ind][pre-'0'];
        if(pre=='0'){
            if(s[ind]=='0') return dp[ind][pre-'0']=min(solve(s,ind+1,pre),1+solve(s,ind+1,'1'));
            else return dp[ind][pre-'0']=min(solve(s,ind+1,'1'),1+solve(s,ind+1,'0'));
        }
        if(s[ind]=='0') return dp[ind][pre-'0']=1 + solve(s,ind+1,'1');
        return dp[ind][pre-'0']=solve(s,ind+1,'1');
    }
    int minFlipsMonoIncr(string s) {
        dp.resize(s.size()+1,vector<int>(2,-1));
        return solve(s,0,'0');
    }
};