//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int pro = 1;
           int cnt = 0;
           int mx_ans = 0;
           for(int i=0;i<n;i++){
               if(arr[i]==0){
                   pro = 1;
                   cnt = 0;
                   continue;
               }
               cnt++;
               if(arr[i]<0) pro*=-1;
               if(pro>0) mx_ans = max(mx_ans,cnt); 
           }
           cnt = 0;
           pro = 1;
           for(int i=n-1;i>=0;i--){
               if(arr[i]==0){
                   pro = 1;
                   cnt = 0;
                   continue;
               }
               cnt++;
               if(arr[i]<0) pro*=-1;
               if(pro>0) mx_ans = max(mx_ans,cnt); 
           }
           return mx_ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends