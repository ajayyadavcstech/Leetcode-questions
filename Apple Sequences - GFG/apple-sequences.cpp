//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int ans = 0;
        int j = 0;
        for(int i=0;i<n;i++){
           
            if(arr[i]=='A') ;
            else if(m) m--;
            else{
                while(!m && i>j){
                    if(arr[j]=='O') m++;
                    j++;
                }
                m--;
            }
            ans = max(i-j+1,ans);
        }
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends