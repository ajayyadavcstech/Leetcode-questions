class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int n = arr.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        vis[0]++;
        q.push(0);
        int stp = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                int ind = q.front();
                q.pop();
                if(ind==n-1) return stp;
                if(ind+1<n && vis[ind+1]==0){
                    vis[ind+1]++;
                    q.push(ind+1);
                }
                if(ind-1>=0 && vis[ind-1]==0){
                    vis[ind-1]++;
                    q.push(ind-1);
                }
                for(auto &x:mp[arr[ind]]){
                    if(!vis[x]){
                        vis[x]++;
                        q.push(x);
                    }
                }
                mp.erase(arr[ind]);
            }
            stp++;
        }
        return -1;
    }
};