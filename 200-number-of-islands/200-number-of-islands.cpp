class Solution {
public:
    int fillWater(vector<vector<char>>&grid,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        
        while(q.size()){
            pair<int,int> front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
                
            if(row+1<grid.size() && grid[row+1][col]=='1'){
                q.push({row+1,col});
                grid[row+1][col] = '0';
            }
                
            if(row-1>=0 && grid[row-1][col]=='1'){
                q.push({row-1,col});
                grid[row-1][col] = '0';
            }
                
            if(col+1<grid[0].size() && grid[row][col+1]=='1'){
                q.push({row,col+1});
                grid[row][col+1] = '0';
            }
                
            if(col-1>=0 && grid[row][col-1]=='1'){
                q.push({row,col-1});
                grid[row][col-1] = '0';
            }
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int totalIsland = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1') totalIsland+=fillWater(grid,i,j);
            }
        }
        return totalIsland;
    }
};