//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here
        vector<vector<long long>> house(N,vector<long long>(3));
        house[N-1] = {r[N-1],g[N-1],b[N-1]};
        for(int i=N-2;i>=0;i--){
            house[i][0] =((long) r[i]) + min(house[i+1][1],house[i+1][2]);
            house[i][1] = ((long)g[i]) + min(house[i+1][0],house[i+1][2]);
            house[i][2] = ((long)b[i]) + min(house[i+1][0],house[i+1][1]);
        }
        return min(house[0][0],min(house[0][1],house[0][2]));
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
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends