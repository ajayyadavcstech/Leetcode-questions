//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        int j = 0;
        int l=-1,r=-1;
        int mx_zero = 0;
        int mx_one = 0;
        int one = 0;
        int zero = 0;
        for(int i=0;i<n;i++){
            if(str[i]=='1') one++;
            else zero++;
            while(zero<one && i>=j){
                if(str[j]=='1') one--;
                else zero--;
                j++;
            }
            // cout<<i<<" "<<j<<" "<<one<<" "<<zero<<endl;
            if(zero-one > mx_zero-mx_one){
                mx_zero = zero;
                mx_one = one;
                l = j;
                r = i;
            }
        }
        vector<int> ans;
        if(r==-1) ans.push_back(-1);
        else ans = {l+1,r+1};
        return ans;
    } //48
// 100111101000000100100100110000100111111010110011
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends