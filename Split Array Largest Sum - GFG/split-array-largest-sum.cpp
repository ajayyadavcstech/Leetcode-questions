//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool solve(int m,int arr[],int n,int k){
      int sum = 0;
      int i = 0;
      while(i<n){
          if((sum+arr[i])>m){
              k--;
              sum = 0;
          }
          else {
            sum+=arr[i];
            i++;
          }
          if(k==0) break;
      }
      return i==n ? true : false;
  }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int i = 1;
        int j = 0;
        
        for(int i=0;i<N;i++) j+=arr[i];
        int ans = -1;
        while(i<=j){
            int mid = (i+j)/2;
            if(solve(mid,arr,N,K)){
                ans = mid;
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends