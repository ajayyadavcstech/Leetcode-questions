//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> rc = {{1,-1,0,0},{0,0,1,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){ 
                    q.push({i,j});
                    c[i][j] = 'N';
                }
            }
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        int stp = 0;
        while(q.size()){
            int size = q.size();
            stp++;
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int row = rc[0][k] + i;
                    int col = rc[1][k] + j;
                    if(row<0 || row==n || col<0 || col==m || c[row][col]=='N') continue;
                    if(c[row][col]=='H') ans[row][col] = 2*stp;
                    c[row][col] = 'N';
                    q.push({row,col});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='H' && ans[i][j]==0) ans[i][j] = -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends