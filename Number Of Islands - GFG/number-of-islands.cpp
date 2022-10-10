//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0) return ;
        
        grid[i][j] = 0;
        
        solve(grid,i+1,j);
        solve(grid,i-1,j);
        solve(grid,i,j+1);
        solve(grid,i,j-1);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        vector<int> ans;
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(int i=0;i<op.size();i++){
            grid[op[i][0]][op[i][1]] = 1;
            vector<vector<int>> temp = grid;
            int cnt = 0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(temp[i][j]){
                        cnt++;
                        solve(temp,i,j);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends