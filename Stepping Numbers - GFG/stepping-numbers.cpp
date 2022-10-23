//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void solve(int &n,int &m,int cur,int &ans){
        if(cur>m) return ;
        if(cur>=n) ans++;
        
        int last = cur%10;
        if(last-1>=0)  solve(n,m,cur*10+(last-1),ans);
        if(last+1<=9) solve(n,m,cur*10+(last+1),ans);
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        int ans = 0;
        if(n==0) ans++;
        for(int i=1;i<=9;i++){
            solve(n,m,i,ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends