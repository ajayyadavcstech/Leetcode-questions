class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int,vector<int>> mp;
        int cnt = 0;
        for(auto x : properties) mp[x[0]].push_back(x[1]);
        vector<int> maxi(mp.size());
        int mx = -1;
        int i = mp.size()-1;
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            for(auto x : it->second){
                mx = max(mx,x);
            }
            maxi[i--] = mx;
        }
        i = 0;
        for(auto it : mp){
            if(i==mp.size()-1) continue;
            for(auto x : it.second){
                if(x<maxi[i+1]) cnt++;
            }i++;
        }
        return cnt;
    }
};