//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int n1 = max(a,max(b,c));
        int n2 = a+b+c-n1;
        if(n1<n2) swap(n1,n2);
        int n = a+b+c;
        while(n){
            if(n1==n2 || (n1<=2 && n2==0)) return a+b+c;
            if(n2==0) break;
            n1-=2;
            n2--;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends