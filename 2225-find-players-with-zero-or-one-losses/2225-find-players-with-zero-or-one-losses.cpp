class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,pair<int,int>> mp;
        int mx = INT32_MIN;
        for(auto &x:matches){
            mp[x[0]].first++;
            mp[x[1]].second++;
            mx = max(mx,max(x[0],x[1]));
        }
        vector<vector<int>> ans(2);
        for(int i=1;i<=mx;i++){
            if(mp.count(i)){
                if(mp[i].second==0) ans[0].push_back(i);
                if(mp[i].second==1) ans[1].push_back(i);
            }
        }
        return ans;
    }
};