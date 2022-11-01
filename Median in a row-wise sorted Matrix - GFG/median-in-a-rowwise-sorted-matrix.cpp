//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(vector<vector<int>> &matrix,int val){
        int cnt = 0;
        for(auto &v: matrix){
            auto pt = upper_bound(v.begin(),v.end(),val);
            cnt+=(pt-v.begin());
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here 
        int n = R*C;
        int ans = 0;
        int i = 1;
        int j = 2000;
        while(i<=j){
            int mid = (i+j)/2;
            int cnt = solve(matrix,mid);
            if(cnt>=(n+1)/2){
                j=mid-1;
                ans = mid;
            }
            else i = mid+1;
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends