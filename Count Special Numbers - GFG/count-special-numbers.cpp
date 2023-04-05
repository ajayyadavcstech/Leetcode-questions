//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        int mx = -1;
        int ans = 0;
        for(auto &x:arr) mx = max(mx,x);
        vector<int> div(mx+1,0);
        for(int i=0;i<arr.size();i++){
            if(div[arr[i]]>1) continue;
            for(int j=arr[i];j<div.size();j+=arr[i]) div[j]++;
        }
        for(int i=0;i<N;i++) if(div[arr[i]]>1) ans++;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends