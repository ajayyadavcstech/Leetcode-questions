//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        vector<int> bit(32,0);
        int i = 31;
        while(n){
            int set_bit = n&1;
            bit[i--] = set_bit;
            n = n>>1;
        }
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(bit[i]==1) cnt++;
            else cnt = 0;
            if(cnt==3){
                cnt = 0;
                bit[i] = 0;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++){
            ans = ans<<1;
            ans = ans|bit[i];
        }
        return ans;
    }
};// 


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends