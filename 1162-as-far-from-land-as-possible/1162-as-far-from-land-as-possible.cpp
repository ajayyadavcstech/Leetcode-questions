class Solution {
public:
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};
    bool is_pos(int r,int c,vector<vector<int>> &dp){
        if(r==-1 || c==-1 || r==dp.size() || c==dp.size() || dp[r][c]!=-1) return false;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        queue<vector<int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dp[i][j] = 0;
                    pq.push({i,j});
                }
            }
        }
        int stp = 0;
        int ans = -1;
        while(pq.size()){
            int size = pq.size();
            stp++;
            while(size--){
                int r = pq.front()[0];
                int c = pq.front()[1];
                pq.pop();
                for(int i=0;i<4;i++){
                    if(is_pos(r+row[i],c+col[i],dp)){
                        pq.push({r+row[i],c+col[i]});
                        dp[r+row[i]][c+col[i]] = stp;
                        ans = max(ans,stp);
                    }
                }
            }
        }
        return ans;        
    }
};