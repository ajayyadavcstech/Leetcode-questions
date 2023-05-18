//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void solve(vector<vector<int>> &mat,int i,int j){
        static vector<vector<int>> rc = {{1,-1,0,0},{0,0,-1,1}};
        if(i<0 || j<0 || i==mat.size() || j==mat[0].size() || mat[i][j]==0) return ;
        mat[i][j] = 0;
        for(int k=0;k<4;k++){
            solve(mat,i+rc[0][k],j+rc[1][k]);
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        int ans = 0;
        for(int i=0;i<N;i++){
            solve(matrix,i,0);
            solve(matrix,i,matrix[0].size()-1);
        } 
        for(int i=0;i<M;i++){
            solve(matrix,0,i);
            solve(matrix,matrix.size()-1,i);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j]==1){
                    solve(matrix,i,j);
                    ans++;
                }        
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends