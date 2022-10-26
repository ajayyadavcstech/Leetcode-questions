//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int solve(int arr[],int&ind,vector<int>& num,int s,int e,int n){
        if(ind==n) return 0;
        if(!(arr[ind]>=s && arr[ind]<=e)) return 0;
        int i = ind;
        ind++;
        int left = solve(arr,ind,num,s,arr[i],n);
        int right = solve(arr,ind,num,arr[i],e,n);
        if(!left && !right) num.push_back(arr[i]);
        return 1;
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int> ans;
        int ind = 0;
        solve(arr,ind,ans,INT32_MIN,INT32_MAX,N);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends