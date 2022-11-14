//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int ans = 0;
        while(1){
            int j = 0;
            for(int i=0;i<S.size();i++){
                if(S[i]==W[j]) {
                    j++;
                    S[i] = ' ';
                }
                if(j==W.size()) break;
            }
            if(j!=W.size()) break;
            ans++;
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends