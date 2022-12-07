//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        int n = 1000003;
        vector<bool> prime(n,1);
        for(int i=4;i<n;i+=2){
            prime[i] = false;
        }
        for(int i=3;i<n;i+=2){
            for(int j=i*2;j<n;j=j+i){
                prime[j] = false;
            }
        }
        int p = 0;
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            if(prime[i]) p++;
            dp[i] = p;
        }
        vector<int> ans;
        for(auto &x:query){
            ans.push_back(dp[sqrt(x)]-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends