//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = 0;
        int mx = 0;
        int cur = 0;
        while(j<arr.size()){
            if(arr[j]-arr[i]<=k) {
                cur++;
                j++;
            }
            else {
                i++;
                cur--;
            }
            mx = max(mx,cur);
        }
        return arr.size()-mx;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends