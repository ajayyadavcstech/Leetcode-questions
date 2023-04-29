//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        map<int,int> mp;
        for(auto &x:intervals){
            mp[x[0]]++;
            if(mp.count(x[1])==0) mp[x[1]] = 0;
            mp[x[1]+1]--;
        }
        int cur = 0;
        int ans = -1;
        
        for(auto &x:mp){
            cur+=x.second;
            if(cur>=k) ans = max(ans,x.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends