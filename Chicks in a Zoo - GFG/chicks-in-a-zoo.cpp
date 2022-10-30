//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    vector<long long> dp(n);
	    long long total = 1;
	    dp[0] = 1;
	    for(int i=1;i<n;i++){
	        if(i<6){
	            dp[i] = total*2;
	            total+=dp[i];
	        }
	        else{
	            total-=dp[i-6];
	            dp[i] = total*2;
	            total+=dp[i];
	        }
	    }
	    return total;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends