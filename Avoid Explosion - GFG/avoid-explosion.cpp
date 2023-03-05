//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int parent(int i,vector<int>&par){
      if(i==par[i]) return i;
      return par[i] = parent(par[i],par);
  }
  void Union(int a,int b,vector<int>&par,vector<int> &size){
      int p1 = parent(a,par);
      int p2 = parent(b,par);
      if(p1==p2) return ;
      if(size[p1]<size[p2]){
          par[p1] = p2;
          size[p2] +=size[p1];
          
      }
      else{
          par[p2] = p1;
          size[p1]+=size[p2];
      }
      
  }
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,vector<vector<int>> danger, int m) {
        vector<int> par(n+1),size(n+1,1);
        vector<string> ans;
        for(int i=0;i<=n;i++) par[i]=i;
        for(auto &x:mix){
            int p1 = parent(x[0],par);
            int p2 = parent(x[1],par);
            bool pois = false;
            for(auto &arr:danger){
                int a1 = parent(arr[0],par);
                int a2 = parent(arr[1],par);
                if(min(a1,a2)==min(p1,p2) && max(a1,a2)==max(p1,p2)){
                    pois = true;
                    break;
                }
            }
            if(pois) ans.push_back("No");
            else{
                ans.push_back("Yes");
                Union(p1,p2,par,size);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends