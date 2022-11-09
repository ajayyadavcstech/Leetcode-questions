//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  int max_sum = 0;
  int max_ans = 0;
  void solve(int arr[],int i,int n,int cur_sum,vector<vector<int>>&dp){
      if(i==n) {
        max_ans = (abs(max_sum-2*max_ans))>=(abs(max_sum-2*cur_sum)) ? cur_sum : max_ans;
        return ;
      }
      if(dp[i][cur_sum]!=-1) return ;
      dp[i][cur_sum] = 1;
      solve(arr,i+1,n,cur_sum+arr[i],dp);
      solve(arr,i+1,n,cur_sum,dp);
  }
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    for(int i=0;i<n;i++) max_sum+=arr[i];
	    vector<vector<int>> dp(n+1,vector<int>(max_sum+1,-1));
	    solve(arr,0,n,0,dp);
	    return abs(max_sum-2*max_ans);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends