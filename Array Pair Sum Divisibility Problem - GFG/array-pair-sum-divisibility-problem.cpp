//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int> rem(k,0);
        for(auto &x:nums) rem[x%k]++;
        int i=1;
        int j = k-1;
        while(i<j){
            if(rem[i]!=rem[j]) return false;
            i++;
            j--;
        }
        if(rem[0]&1) return false;
        if(k%2==0 && rem[k/2]&1) return false;
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends