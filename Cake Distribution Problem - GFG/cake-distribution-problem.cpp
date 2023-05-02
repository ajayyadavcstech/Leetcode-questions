//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool solve(vector<int>&arr,int t,int k){
        long long sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>=t){
                sum = 0;
                k--;
            }
            if(k==0) return true;
        }
        return false;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
        long long s = 0;
        long long e = 1e15;
        long long ans = 0;
        while(s<=e) {
            long long mid = s + (e-s)/2;
            if(solve(sweetness,mid,K+1)){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends