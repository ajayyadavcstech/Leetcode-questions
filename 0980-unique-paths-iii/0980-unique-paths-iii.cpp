class Solution {
public:
    int ans = 0;
    vector<int> r = {0,0,1,-1};
    vector<int> c = {1,-1,0,0};
    bool is_pos(vector<vector<int>>&grid,int i,int j){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && (grid[i][j]==0 || grid[i][j]==2)) return true;
        return false;
    }
    void solve(vector<vector<int>>&grid,int i,int j,int &t_cnt,int cur_cnt){
        
        if(grid[i][j]==2 && cur_cnt==t_cnt) {
            ans++;
            return ;
        }
        
        if(grid[i][j]==2) return ;
        int val = grid[i][j];
        grid[i][j] = 3;
        for(int k=0;k<4;k++){
            if(is_pos(grid,i+r[k],j+c[k])){
                solve(grid,i+r[k],j+c[k],t_cnt,cur_cnt+1);
            }
        }
        grid[i][j] = val;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt = 0;
        int row,col;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) cnt++;
                if(grid[i][j]==1){
                    row=i;
                    col=j;
                }
            }
        }
        cnt+=2;
        solve(grid,row,col,cnt,1);
        return ans;
    }
};