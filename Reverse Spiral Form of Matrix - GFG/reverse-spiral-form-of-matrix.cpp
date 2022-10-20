//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        int row_start=0;
        int row_end=R-1;
        int col_start=0;
        int col_end=C-1;
        vector<int> v;
        while(row_start<=row_end && col_start<=col_end){
            for(int i=col_start;i<=col_end;i++){
                v.push_back(a[row_start][i]);
            }
            row_start++;
            if(row_start>row_end) break;
            for(int i=row_start;i<=row_end;i++){
                v.push_back(a[i][col_end]);
            }
            col_end--;
            if(col_start>col_end) break;
            for(int i=col_end;i>=col_start;i--){
                v.push_back(a[row_end][i]);
            }
            row_end--;
            if(row_start>row_end) break;
            for(int i=row_end;i>=row_start;i--){
                v.push_back(a[i][col_start]);
            }
            col_start++;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends