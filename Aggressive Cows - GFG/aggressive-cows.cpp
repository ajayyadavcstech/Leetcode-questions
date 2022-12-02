//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool is_possible(vector<int>&st,int val,int k){
        int pre = 0;
        k--;
        for(int i=0;i<st.size();i++){
            if(st[i]-st[pre]>=val){
                k--;
                pre = i;
            }
            if(k==0) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &st) {
    
        // Write your code here
        sort(st.begin(),st.end());
        int i = 0;
        int j = st[n-1];
        int ans = -1;
        while(i<=j){
            int mid = j + (i-j)/2;
            if(is_possible(st,mid,k)){
                i = mid+1;
                ans = mid;
            }
            else{
                j = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends