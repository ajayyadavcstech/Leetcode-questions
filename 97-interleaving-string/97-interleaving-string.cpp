class Solution {
public:
    vector<vector<int>> dp;
    bool Solve(string &s1,string &s2,string &s3,int i,int j,int k){
        if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
        if((i==s1.size() && j==s2.size() && k!=s3.size()) || (k==s3.size() && (i!=s1.size() || j!=s2.size())))  return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool isMatching = false;
        if(i!=s1.size() && j!=s2.size() && s1[i]==s3[k] && s2[j]==s3[k]){
            isMatching =  Solve(s1,s2,s3,i+1,j,k+1) || Solve(s1,s2,s3,i,j+1,k+1);
        }
        else if(i!=s1.size() && s1[i]==s3[k]){
            isMatching = Solve(s1,s2,s3,i+1,j,k+1);
        }
        else if(j!=s2.size() && s2[j]==s3[k]){
            isMatching = Solve(s1,s2,s3,i,j+1,k+1);
        }
        
        return dp[i][j] = isMatching;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return Solve(s1,s2,s3,0,0,0);
    }
};