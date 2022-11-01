class Solution {
public:
    int solve(vector<vector<int>>&grid,int j){
        int i = 0;
        while(i<grid.size()){
            if((grid[i][j]==1 && j==grid[0].size()-1) || (grid[i][j]==-1 && j==0)) return -1;
            if(grid[i][j]==1 &&grid[i][j+1]==1){
                i++;
                j++;
            }
            else if(grid[i][j]==-1 && grid[i][j-1]==-1) {
                i++;
                j--;
            }
            else return -1;
        }
        return j;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int i=0;i<ans.size();i++){
            ans[i] = solve(grid,i);
        }
        return ans;
    }
};