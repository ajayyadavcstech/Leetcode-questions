class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        vis[0]=true;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int f = q.front();
            q.pop();
            for(auto &x:rooms[f]){
                if(vis[x]==false){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
        for(auto x:vis) if(x==false) return false;
        return true;
    }
};