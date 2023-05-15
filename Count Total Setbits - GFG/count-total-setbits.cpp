//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        long long ans = 0;
        for(int i=0;i<=30;i++){
            long long grp = (N+1)/(1<<(i+1));
            long long one = grp*(1<<i);
            ans+=one;
            
            long long rem = (N+1)%(1<<(i+1));
            ans+=(max(0ll,rem-(1<<i)));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends