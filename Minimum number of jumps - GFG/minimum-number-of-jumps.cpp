//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        int cur_step = 0;
        int min_step = 0;
        int pre = 0;
        
        int i = 0;
        while(i<n){
            cur_step = arr[pre]-(i-pre);
            if(cur_step==0 && arr[i]==0) return -1;
            min_step++;
            if(cur_step+i>=n-1)  break;
            pre = i+1;
            for(int j=1;j<=cur_step;j++){
                if((i+j+arr[i+j])>(pre+arr[pre])) pre = i+j;
            }
            i = i+cur_step;
        }
        return min_step;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends