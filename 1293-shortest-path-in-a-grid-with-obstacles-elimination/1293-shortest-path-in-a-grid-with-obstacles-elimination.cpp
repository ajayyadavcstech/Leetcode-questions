class Solution {
public:
    bool isSafe(int i,int j,vector<vector<int>>& grid){
        if(i==grid.size() || j==grid[0].size() || i==-1 || j==-1) return false;
        return true;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>> q;
        set<vector<int>> visited;
        visited.insert({0,0,k});
        int n = 0;
        q.push({0,0,k});
        while(q.size()){
            int s = q.size();
            while(s--){
                vector<int> v = q.front();
                int i = v[0];
                int j = v[1];
                int k = v[2];
                if(i==grid.size()-1 && j==grid[0].size()-1) return n;
                q.pop();
                
                if(isSafe(i+1,j,grid)) {
                    if(grid[i+1][j] && visited.count({i+1,j,k-1})==0 && k>0){
                       q.push({i+1,j,k-1});
                       visited.insert({i+1,j,k-1});
                    } 
                    else if(grid[i+1][j]==0 && visited.count({i+1,j,k})==0) {
                        q.push({i+1,j,k});
                        visited.insert({i+1,j,k});
                    }
                }
                
                if(isSafe(i-1,j,grid)) {
                    if(grid[i-1][j] && visited.count({i-1,j,k-1})==0 && k>0) {
                        q.push({i-1,j,k-1});
                        visited.insert({i-1,j,k-1});
                    }
                    else if(grid[i-1][j]==0 && visited.count({i-1,j,k})==0) {
                        q.push({i-1,j,k});
                        visited.insert({i-1,j,k});
                    
                    }
                }
                
                if(isSafe(i,j+1,grid)) {
                    if(grid[i][j+1] && visited.count({i,j+1,k-1})==0 && k>0) {
                        q.push({i,j+1,k-1});
                        visited.insert({i,j+1,k-1});
                    }
                    else if(grid[i][j+1]==0 && visited.count({i,j+1,k})==0) {
                        q.push({i,j+1,k});
                        visited.insert({i,j+1,k});
                    }
                }
                
                if(isSafe(i,j-1,grid)) {
                    if(grid[i][j-1] && visited.count({i,j-1,k-1})==0 && k>0) {
                        q.push({i,j-1,k-1});
                        visited.insert({i,j-1,k-1});
                    }
                    else if(grid[i][j-1]==0 && visited.count({i,j-1,k})==0) {
                        q.push({i,j-1,k});
                        visited.insert({i,j-1,k});
                    }
                }
            }n++;
        }
        return -1;
    }
};