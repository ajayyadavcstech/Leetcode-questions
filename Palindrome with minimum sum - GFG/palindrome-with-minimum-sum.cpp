//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool check(string &str){
        int s = 0;
        int e = str.size()-1;
        while(s<e){
            if(str[s]!='?' && str[e]!='?' && str[s]!=str[e]) return false;
            if(str[s]!='?') str[e] = str[s];
            else if(str[e]!='?') str[s] = str[e];
            s++;e--;
        }
        return true;
    }
    int minimumSum(string str) {
        if(!check(str)) return -1;
        int ans = 0;
        char pre = ' ';
        int s = 0;
        int e = str.size()-1;
        while(s<=e){
            if(str[s]!='?'){
                if(pre==' ') pre = str[s];
                else{
                    ans+=2*abs(str[s]-pre);
                    pre = str[s];
                }
            }
            s++;e--;
        }
        return ans;
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
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends