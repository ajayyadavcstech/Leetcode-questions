class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        map<int,int> end;
        for(auto &x:p){
            end[x[1]]++;
        }
        int ans = 0;
        int i = 0;
        for(auto &x:end){
            if(x.second==0) continue;
            ans++;
            while(i<p.size() && p[i][0]<=x.first){
                end[p[i][1]]--;
                i++;
            }
        }
        return ans;
    }
};