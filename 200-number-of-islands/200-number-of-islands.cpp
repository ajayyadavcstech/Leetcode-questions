class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>& grid){
        if(i==grid.size() || i<0 || j==grid[0].size() || j<0 || grid[i][j]=='0' || visited[i][j]) return ;
        visited[i][j]++;
        dfs(i+1,j,visited,grid);
        dfs(i-1,j,visited,grid);
        dfs(i,j+1,visited,grid);
        dfs(i,j-1,visited,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,visited,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};