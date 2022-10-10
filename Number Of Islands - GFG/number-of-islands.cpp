//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> parent;
    int get_parent(int n){
        if(parent[n]==n) return n;
        return get_parent(parent[n]);
    }
    int union_set(int p1,int p2){
        p1 = get_parent(p1);
        p2 = get_parent(p2);
        parent[p1] = p2;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        vector<vector<int>> grid(n,vector<int>(m,0));
        parent.resize(n*m);
        vector<int> ans;
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
        for(int i=0;i<op.size();i++){
            int k = op[i][0];
            int l = op[i][1];
            int ind = k*m + l;
            if(grid[k][l]==0){
                grid[k][l] = 1;
                if(k+1<n && grid[k+1][l]){
                    union_set(ind,ind+m);
                }
                if(k-1>=0 && grid[k-1][l]){
                    union_set(ind,ind-m);
                }
                if(l+1<m && grid[k][l+1]){
                    union_set(ind,ind+1);
                }
                if(l-1>=0 && grid[k][l-1]){
                    union_set(ind,ind-1);
                }
            }
            int cnt = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int ind = i*m+j;
                    if(grid[i][j] && parent[ind]==ind) cnt++;
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