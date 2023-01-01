//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long expo(long long a,long long b,int &mod){
	    if(b==0) return 1;
	    if(b==1) return a;
	    if(b&1) return a*expo((a*a)%mod,b/2,mod)%mod;
	    long long num =  expo((a*a)%mod,b/2,mod);
	    return (num)%mod;
	}
	void pre_cop(int n,vector<long long> &fac,vector<long long>&ifac,int mod){
	    fac[0] = fac[1] = 1;
	    ifac[0] = ifac[1] = pow(1,mod-2);
	    for(int i=2;i<=n;i++){
	        fac[i] = (i*fac[i-1])%mod;
	        ifac[i] = expo(fac[i],mod-2,mod);
	    }
	}
	int compute_value(int n)
	{
	    // Code here
	    int mod = 1e9+7;
	    vector<long long> fac(2*n+1);
	    vector<long long> ifac(2*n+1);
	    pre_cop(2*n,fac,ifac,1e9+7);
	    long long ans = fac[2*n]*((ifac[n]*ifac[n])%mod)%mod;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends