//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool is_pos(int i,int j,vector<vector<int>>&v){
        if(i<0 || j<0 || i==v.size() || j==v[0].size() || v[i][j]!=INT32_MAX) return false;
        return true;
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    vector<int> row = {0,0,1,-1};
	    vector<int> col = {1,-1,0,0};
	    vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),INT32_MAX));
	    queue<vector<int>> pq;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]){
	                ans[i][j] = 0;
	                pq.push({i,j});
	            }
	        }
	    }
	    int step = 0;
	    while(pq.size()){
	        int n = pq.size();
	        step++;
	        while(n--){
	            int i = pq.front()[0];
	            int j = pq.front()[1];
	            pq.pop();
	            for(int k=0;k<4;k++){
	                if(is_pos(row[k]+i,col[k]+j,ans)){
	                    ans[row[k]+i][col[k]+j] = step;
	                    pq.push({row[k]+i,col[k]+j});
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends