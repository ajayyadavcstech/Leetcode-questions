class Solution {
public:
    vector<int> Vx = {1,-1,0,0};
    vector<int> Vy = {0,0,1,-1};
    vector<vector<int>> visited;    
    vector<vector<pair<int,pair<bool,bool>>>> dp;
    pair<bool,bool> isWay(vector<vector<int>>& heights,int i,int j,int pre){
        if(i==-1 || j==-1) return {true,false};
        if(i==heights.size() || j==heights[0].size()) return {false,true};
        if(pre<heights[i][j]) return {false,false};
        if(visited[i][j]) return {false,false};
        if(dp[i][j].first==1) return dp[i][j].second;
        
        visited[i][j] = true;
        pair<bool,bool> ans = {false,false};
        for(int k=0;k<4;k++){
            pair<bool,bool> p = isWay(heights,i+Vx[k],j+Vy[k],heights[i][j]);
            ans.first = ans.first || p.first;
            ans.second = ans.second || p.second;
            if(ans.first && ans.second) {
                visited[i][j] = false;
                dp[i][j].first = 1;
                return dp[i][j].second = ans;
            }
        }
        visited[i][j] = false;
        return ans;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        visited.resize(n,vector<int>(m,0));        
        dp.resize(n,vector<pair<int,pair<bool,bool>>>(m,{-1,{false,false}}));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pair<bool,bool> p = isWay(heights,i,j,INT32_MAX);
                if(p.first && p.second) ans.push_back({i,j});
            }
        }
        return ans;
    }
};