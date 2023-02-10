//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int> mp;
        for(auto &x:s) mp[x]++;
        string str = "balon";
        int mx = INT32_MAX;
        for(auto &x:str){
            if(x=='l' || x=='o') mx = min(mx,mp[x]/2);
            else mx = min(mx,mp[x]);
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends