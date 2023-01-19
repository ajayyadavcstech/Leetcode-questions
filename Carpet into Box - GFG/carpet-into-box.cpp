//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int a = max(A,B);
        int b = min(A,B);
        int c = max(C,D);
        int d = min(C,D);
        int cnt = 0;
        while(!(a<=c && b<=d)){
            cnt++;
            if(a>c) a/=2;
            else b/=2;
            A = a;
            B = b;
            a = max(A,B);
            b = min(A,B);
        }
        return cnt;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends