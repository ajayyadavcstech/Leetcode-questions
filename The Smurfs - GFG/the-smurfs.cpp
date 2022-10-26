//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int count_r = 0,count_b = 0,count_g = 0 ;
        for(int i=0;i<n;i++){
            if(a[i]=='G') count_g++;
            else if(a[i]=='R') count_r++;
            else count_b++;
        }
        if((count_r==0 && count_b==0) || (count_g==0 && count_b==0) || (count_r==0 && count_g==0)) return max(count_r,max(count_b,count_g));
        if((count_r&1 && count_b&1 && count_g&1) || (!(count_r&1) && !(count_b&1) && !(count_g&1))) return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends