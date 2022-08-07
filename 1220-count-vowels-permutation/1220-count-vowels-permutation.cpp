class Solution {
public:
    int mod = 1000000007;
    void mapping(unordered_map<char,vector<char>> &mp){
        vector<char> ch = {'a','e','i','o','u'};
        mp['0'].insert(mp['0'].end(),ch.begin(),ch.end());
        //for a
        mp['a'].push_back('e');
        //for e
        mp['e'].push_back('a');
        mp['e'].push_back('i');
        //for i
        mp['i'].push_back('a');
        mp['i'].push_back('e');        
        mp['i'].push_back('o');
        mp['i'].push_back('u');
        //for o
        mp['o'].push_back('i');
        mp['o'].push_back('u');
        //for u
        mp['u'].push_back('a');
    }
    long solve(unordered_map<char,vector<char>>&mp,vector<unordered_map<char,int>>&dp,int n,char pre){
        if(n==0) return 1;
        int cnt = 0;
        if(dp[n].count(pre)!=0) return dp[n][pre];
        for(auto x : mp[pre]){
            cnt=(cnt+solve(mp,dp,n-1,x))%mod;
        }
        return dp[n][pre] = cnt;
    }
    int countVowelPermutation(int n) {
        unordered_map<char,vector<char>> mp;
        vector<unordered_map<char,int>> dp(n+1);
        mapping(mp);
        return solve(mp,dp,n,'0');
    }
};