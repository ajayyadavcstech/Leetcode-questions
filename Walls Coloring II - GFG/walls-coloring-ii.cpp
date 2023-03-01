//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        int k = costs[0].size();
        if(n==0 || k==0) return 0;
        if(n!=1 && k==1) return -1;
        vector<long long> nums(k,0);
        for(int i=0;i<k;i++) nums[i] = costs[0][i];
        for(int i=1;i<n;i++){
            int mn1 = INT32_MAX;
            int mn2 = INT32_MAX;
            vector<long long> temp(k);
            for(int j=0;j<k;j++){
                if(nums[j]<=mn1){
                    mn2 = mn1;
                    mn1 = nums[j];
                }
                else if(nums[j]<=mn2) mn2 = nums[j];
            }
            for(int j=0;j<k;j++){
                if(nums[j]==mn1) temp[j] = mn2 + costs[i][j];
                else temp[j] = mn1 + costs[i][j];
            }
            nums = temp;
        }
        long long mn = INT32_MAX;
        for(int i=0;i<k;i++) mn = min(mn,nums[i]);
        return mn;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends