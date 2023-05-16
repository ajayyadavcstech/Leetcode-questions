//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int solve(int i,string s,vector<int>&dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return INT32_MAX;
        int mn = INT32_MAX;
        long long x = 0;
        for(int j=i;j<s.size();j++){
            x = x<<1;
            x = x | (s[j]=='1' ? 1 : 0);
            int n = log2(x)/log2(5);
            // if(i==0 && j==s.size()-1) cout<<x<<" "<<n<<" "<<log10(x)<<" "<<log10(5);
            if(x>0 && powl(5,n)==x){
                // cout<<x<<" ";
                int next = solve(j+1,s,dp);
                mn = min(mn,next);
            }
        }
        // cout<<mn<<" "<<i<<endl;
        return dp[i] = mn==INT32_MAX ? mn : mn+1;
    }
    int cuts(string s){
        //code
        vector<int> dp(s.size(),-1);
        int ans = solve(0,s,dp);
        return ans==INT32_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends