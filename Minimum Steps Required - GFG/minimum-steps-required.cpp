//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int cnt_a = 0;
    int cnt_b = 0;
    if(str[0]=='a') cnt_a++;
    else cnt_b++;
    for(int i=0;i<str.size();i++){
        if(str[i]==str[i-1]) continue;
        if(str[i]=='a') cnt_a++;
        else cnt_b++;
    }
    return min(cnt_a,cnt_b)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends