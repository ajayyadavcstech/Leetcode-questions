//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   int rc[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
     vector<vector<pair<bool,bool>>> vis(N,vector<pair<bool,bool>>(M,{false,false}));
     long long ans = 0;
     queue<vector<int>> q;
     for(int i=0;i<N;i++){
        q.push({i,0,0});
        vis[i][0].first = true;
        q.push({i,M-1,1});
        vis[i][M-1].second = true;
        if(vis[i][M-1].first==1) ans++;
     }
     for(int j=0;j<M;j++){
        if(vis[0][j].first==false){
            q.push({0,j,0});
            vis[0][j].first = true;
            if(vis[0][j].second==true) ans++;
        }
        if(vis[N-1][j].second==false){
            q.push({N-1,j,1});
            vis[N-1][j].second = true;
            if(vis[N-1][j].first==true) ans++;
        }
     }
     while(q.size()){
         int i = q.front()[0];
         int j = q.front()[1];
         int oc = q.front()[2];
         q.pop();

         for(int k=0;k<4;k++){
             int r = rc[k][0]+i;
             int c = rc[k][1]+j;
             if(r<N && c<M && r>=0 && c>=0 && mat[i][j]<=mat[r][c]){
                 if(oc==0 && vis[r][c].first==false){
                     vis[r][c].first = true;
                     q.push({r,c,0});
                     if(vis[r][c].second==true) ans++;
                 }
                 else if(oc==1 && vis[r][c].second==false){
                     vis[r][c].second = true;
                     q.push({r,c,1});
                     if(vis[r][c].first==true) ans++;
                 }
             }
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
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends