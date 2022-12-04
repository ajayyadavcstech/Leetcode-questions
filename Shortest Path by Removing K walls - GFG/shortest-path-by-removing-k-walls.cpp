//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool is_pos(int i,int j,int m,int n){
      if(i<0 || i==m || j<0 || j==n) return false;
      return true;
  }
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        queue<vector<int>> pq;
        vector<vector<int>> vis(n+1,vector<int>(m+1,-1));
        pq.push({0,0,k});
        vis[0][0] = k;
        int step=0;
        while(pq.size()){
            int size = pq.size();
            while(size--){
                vector<int> temp = pq.front();
                if(temp[0]==n-1 && temp[1]==m-1) return step;
                pq.pop();
                for(int i=0;i<4;i++){
                    int o = row[i]+temp[0];
                    int p = col[i]+temp[1];
                    if(is_pos(o,p,n,m)){
                        if(mat[o][p]==0 && vis[o][p]<temp[2]){
                            pq.push({o,p,temp[2]});
                            vis[o][p] = temp[2];
                        }
                        
                        if(mat[o][p]==1 && vis[o][p]<(temp[2]-1)){
                            pq.push({o,p,temp[2]-1});
                            vis[o][p] = temp[2]-1;
                        }
                    }
                }
                
            }step++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends