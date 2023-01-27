//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod = 1e9+7;
	    long long solve(int ind,string&str,vector<int>&dp){
	        if(ind==str.size()-1 && str[ind]=='0') return 0;
	        if(ind>=str.size()-1) return 1;
	        if(str[ind]=='0') return 0;
	        if(dp[ind]!=-1) return dp[ind];
	        long long cnt = solve(ind+1,str,dp);
	        if((str[ind]=='2') && (str[ind+1]>='0' && str[ind+1]<='6')) cnt+=solve(ind+2,str,dp);
	        else if(str[ind]=='1') cnt+=solve(ind+2,str,dp);
	        return dp[ind] = cnt%mod;
	    }
		int CountWays(string str){
		    // Code here
		    vector<int> dp(str.size()+1,-1);
		    return solve(0,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends