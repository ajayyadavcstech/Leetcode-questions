//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        vector<vector<int>> rc = {{0,0,1,-1},{1,-1,0,0}};
        queue<vector<int>> q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]=='X'){
                 q.push({i,j});
                 grid[i][j] = '1';
                }
            }
        }
        int step = 0;
        while(q.size()){
            int n = q.size();
            step++;
            while(n--){
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();
                for(int k=0;k<4;k++){
                    int r = rc[0][k] + i;
                    int c = rc[1][k] + j;
                    if(r>=0 && r<N && c>=0 && c<M && grid[r][c]!='1'){
                        if(grid[r][c]=='Y') return step; 
                        grid[r][c] = '1';
                        q.push({r,c});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends