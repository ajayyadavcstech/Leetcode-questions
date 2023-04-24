//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && arr[st.top()]>arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=0;i<n;i++){
            while(st.size() && arr[st.top()]>arr[i]){
               if(ans[st.top()]==-1 || ((i-st.top())<(st.top()-ans[st.top()])) || (((i-st.top())==(st.top()-ans[st.top()])) && arr[i]<arr[ans[st.top()]]) ) ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends