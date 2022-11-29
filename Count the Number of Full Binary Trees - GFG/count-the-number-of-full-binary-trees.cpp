//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int mod = 1000000007;
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        long long ans = 0;
        long long mx = 0,mn = 100000000;
        for(int i=0;i<n;i++){
          mx = max(mx,arr[i]);
          mn = min(mn,arr[i]);
        } 
        vector<long long> v(mx+1,0);
        for(int i=0;i<n;i++) v[arr[i]] = 1;
        for(int i=mn;i<=mx;i++){
            if(v[i]==0) continue;
            int cnt = i;
            for(int j = 2*cnt;j<=mx && (j/i)<=i;j+=cnt){
                if(v[j]==0 || v[j/i]==0) continue;
                long long a = v[i];
                long long b = v[j/i];
                v[j]= (v[j] + (a*b))%mod;
                if(i!=(j/i)) v[j]= (v[j] + (a*b))%mod;
            }
            ans = (ans + v[i])%mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends