//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool isPrime(int n){
        if(n!=2 && n%2==0) return false;
        for(int i = 3;i*i<=n;i+=2){
            if(n%i==0) return false;
        }
        return true;
    }
    string isSumOfTwo(int N){
        // code here
        int i = 1;
        int j = N-1;
        while(i<j){
            if(isPrime(i) && isPrime(j)) return "Yes";
            i++;j--;
        }
        return "No";
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
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends