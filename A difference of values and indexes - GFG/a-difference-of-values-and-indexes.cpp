//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        int mxi_1 = INT32_MIN;
        int mxj_1 = INT32_MIN;
        int mxi_2 = INT32_MIN;
        int mxj_2 = INT32_MIN;
        for(int i=0;i<n;i++){
            mxi_1 = max(mxi_1,arr[i]-i);
            mxj_1 = max(mxj_1,i-arr[i]);
            mxi_2 = max(mxi_2,-i-arr[i]);
            mxj_2 = max(mxj_2,arr[i]+i);
        }
        return max(mxi_1+mxj_1,mxi_2+mxj_2);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends