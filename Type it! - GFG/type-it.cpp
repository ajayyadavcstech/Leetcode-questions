//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int cnt = 1;
        for(int i=0;i+i<s.size();i++){
            if(s.substr(0,i+1)==s.substr(i+1,i+1)){
                cnt = i+1;
            }
        }
        return s.size()-cnt+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends