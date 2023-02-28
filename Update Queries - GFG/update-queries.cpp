//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            int n = N;
            vector<int> ans(n);
            vector<vector<int>> arr(N+1,vector<int>(32,0));
            vector<int> bit(32,0);
            for(int i=0;i<Q;i++){
                int l = U[i][0]-1;
                int r = U[i][1]-1;
                int x = U[i][2];
                int j = 0;
                while(x){
                    int bit = x&1;
                    arr[l][j]+=bit;
                    arr[r+1][j]-=bit;
                    x = x>>1;
                    j++;
                }
            }
            for(int i=0;i<n;i++){
                int x = 0;
                for(int j=0;j<32;j++){
                    bit[j]+=arr[i][j];
                    if(bit[j]) x = x|(1<<j);
                }
                ans[i] = x;
            }
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
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends