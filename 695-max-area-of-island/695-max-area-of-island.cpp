class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j){
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size() || grid[i][j]==0) return 0;
        
        grid[i][j]=0;
        return 1 + solve(grid,i+1,j) + solve(grid,i-1,j) + solve(grid,i,j+1) + solve(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]) maxArea = max(maxArea,solve(grid,i,j));
            }
        }
        return maxArea;
    }
};