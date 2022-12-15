//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string even(int N){
        int rep = N/26;
        N = N%26;
        string ans;
        string st = "abcdefghijklmnopqrstuvwxyz";
        while(rep--){
            ans = ans + st;
        }
        ans = ans + st.substr(0,N/2);
        ans = ans + st.substr(26-N/2,N/2);
        return ans;
    }
    string odd_even(int N){
        int rep = N/26;
        N = N%26;
        string ans;
        string st = "abcdefghijklmnopqrstuvwxyz";
        while(rep--){
            ans = ans + st;
        }
        ans = ans + st.substr(0,(N+1)/2);
        ans = ans + st.substr(26-(N-1)/2,(N-1)/2);
        return ans;
    }
    string odd_odd(int N){
        int rep = N/26;
        N = N%26;
        string ans;
        string st = "abcdefghijklmnopqrstuvwxyz";
        while(rep--){
            ans = ans + st;
        }
        ans = ans + st.substr(0,(N-1)/2);
        ans = ans + st.substr(26-(N+1)/2,(N+1)/2);
        return ans;
    }
    string BalancedString(int N) {
        // code here
        if(N%2==0) return even(N);
        int sum = 0;
        int n = N;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        if(sum%2==0) return odd_even(N);
        return odd_odd(N);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends