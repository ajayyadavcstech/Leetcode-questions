class Solution {
public:
    vector<vector<int>> dp;
    int editDistance(string &a,string &b,int i,int j){
        if(i==a.size() || j==b.size()) return a.size()-i+b.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(a[i]==b[j]) return dp[i][j]=editDistance(a,b,i+1,j+1);
        return dp[i][j]=1 + min({editDistance(a,b,i+1,j+1),editDistance(a,b,i+1,j),editDistance(a,b,i,j+1)});
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int>(word2.size(),-1));
        return editDistance(word1,word2,0,0);
    }
};