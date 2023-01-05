//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool solve(string str,unordered_set<string> &st){
        while(str.size()){
            if(st.count(str)==0) return false;
            str.pop_back();
        }
        return true;
    }
    string longestString(vector<string> &words)
    {
        // code here
        unordered_set<string> st;
        for(auto &x:words){
            st.insert(x);
        }
        string ans;
        for(auto &x:words){
            if(solve(x,st)){
                if(ans.size()<x.size()) ans = x;
                else if(ans.size()==x.size() && ans>x) ans = x;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends