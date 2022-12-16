//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool is_pos(int i,int j,vector<vector<int>>&mat){
        if(i==-1 || j==-1 || i==mat.size() || j==mat[0].size() || mat[i][j]==-1) return false;
        return true;
    }
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        queue<vector<int>> pq;
        pq.push({i,j});
        mat[i][j] = -1;
        int stp = 0;
        while(pq.size()){
            int n = pq.size();
            int sum = 0;
            stp++;
            while(n--){
                vector<int> v = pq.front();
                pq.pop();
                int i = v[0];
                int j = v[1];
                if(is_pos(i+1,j,mat)){
                    sum+=mat[i+1][j];
                    mat[i+1][j] = -1;
                    pq.push({i+1,j});
                }
                if(is_pos(i-1,j,mat)){
                    sum+=mat[i-1][j];
                    mat[i-1][j] = -1;
                    pq.push({i-1,j});
                }
                if(is_pos(i,j+1,mat)){
                    sum+=mat[i][j+1];
                    mat[i][j+1] = -1;
                    pq.push({i,j+1});
                }
                if(is_pos(i,j-1,mat)){
                    sum+=mat[i][j-1];
                    mat[i][j-1] = -1;
                    pq.push({i,j-1});
                }
                if(j&1){
                    if(is_pos(i+1,j-1,mat)){
                        sum+=mat[i+1][j-1];
                        mat[i+1][j-1] = -1;
                        pq.push({i+1,j-1});
                    }
                    if(is_pos(i+1,j+1,mat)){
                        sum+=mat[i+1][j+1];
                        mat[i+1][j+1] = -1;
                        pq.push({i+1,j+1});
                    }
                }
                else{
                    if(is_pos(i-1,j-1,mat)){
                        sum+=mat[i-1][j-1];
                        mat[i-1][j-1] = -1;
                        pq.push({i-1,j-1});
                    }
                    if(is_pos(i-1,j+1,mat)){
                        sum+=mat[i-1][j+1];
                        mat[i-1][j+1] = -1;
                        pq.push({i-1,j+1});
                    }
                }
            }
            if(ty==0 && stp==1) return sum;
            else if(stp==2) return sum;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends