class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int ans = 0;
        for(int i=0;i<p.size();i++){
            unordered_map<float,int> mp;
            int mx = 0;
            for(int j=i+1;j<p.size();j++){
                float slope = (p[j][1]-p[i][1])/float(p[j][0]-p[i][0]);
                mp[slope]++;
                mx = max(mx,mp[slope]);
            }
            ans = max(ans,mx+1);
        }
        return ans;
    }
};