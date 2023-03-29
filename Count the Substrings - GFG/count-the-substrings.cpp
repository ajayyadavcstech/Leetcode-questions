//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        vector<int> arr;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') arr.push_back(1);
            else arr.push_back(-1);
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefix = 0;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            prefix+=arr[i];
            cnt+=mp[prefix];
            mp[prefix]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends