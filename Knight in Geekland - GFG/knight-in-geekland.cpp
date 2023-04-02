//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        vector<vector<int>> rc = {{-2,-2,2,2,-1,-1,1,1},{-1,1,-1,1,-2,2,-2,2}};
        vector<long long> point;
        vector<vector<int>> vis(arr.size(),vector<int>(arr[0].size(),0));
        queue<vector<int>> q;
        q.push({start_x,start_y});
        vis[start_x][start_y]++;
        while(q.size()){
            int n = q.size();
            int sum = 0;
            while(n--){
                int r = q.front()[0];
                int c = q.front()[1];
                q.pop();
                sum+=arr[r][c];
                for(int i=0;i<8;i++){
                    int row = r+rc[0][i];
                    int col = c+rc[1][i];
                    if(row>=0 && row<arr.size() && col>=0 && col<arr[0].size() && vis[row][col]==0){
                        vis[row][col]++;
                        q.push({row,col});
                    }
                }
            }
            point.push_back(sum);
        }

        for(int i=point.size()-1;i>=0;i--){
            if(point[i]+i<point.size()) point[i]+=point[i+point[i]];
        }
        int ind = 0;
        for(int i=0;i<point.size();i++){
            if(point[i]>point[ind]) ind = i;
        }
        return ind;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends