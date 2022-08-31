class Solution {
public:
    vector<int> Vx = {1,-1,0,0};
    vector<int> Vy = {0,0,1,-1};
    void bfs(vector<vector<int>> &visited,vector<vector<int>>& heights,queue<pair<int,int>>&q){
        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                if(i+Vx[k]>=0 && j+Vy[k]>=0 && i+Vx[k]<visited.size() && j+Vy[k]<visited[0].size() && !visited[i+Vx[k]][j+Vy[k]] && heights[i+Vx[k]][j+Vy[k]]>=heights[i][j]){
                    visited[i+Vx[k]][j+Vy[k]]++;
                    q.push({i+Vx[k],j+Vy[k]});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>> atlantic(heights.size(),vector<int>(heights[0].size(),0));
        
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        
        for(int i=0;i<heights.size();i++){
            pacific[i][0]++;
            q1.push({i,0});
        }
         for(int i=1;i<heights[0].size();i++){
            pacific[0][i]++;
            q1.push({0,i});
        }
        
        for(int i=0;i<heights.size();i++){
            atlantic[i][heights[0].size()-1]++;
            q2.push({i,heights[0].size()-1});
        }
        for(int i=0;i<heights[0].size()-1;i++){
            atlantic[heights.size()-1][i]++;
            q2.push({heights.size()-1,i});
        }
        
        bfs(pacific,heights,q1);
        bfs(atlantic,heights,q2);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};