//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        stack<int> st;
        vector<int> ans;
        int i=0;
        while(i<N){
            if(st.size()==0 || st.top()>arr[i]) st.push(arr[i++]);
            else{
                int val = st.top();
                int cnt = 0;
                while(st.size() && st.top()<arr[i]){
                    cnt++;
                    st.pop();
                }
                if(cnt>1) ans.push_back(val);
                st.push(arr[i]);
                i++;
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends