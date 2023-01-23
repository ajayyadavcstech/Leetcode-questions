class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,unordered_map<int,int>> mp;
        for(auto &x:trust){
            mp[x[0]][x[1]]++;
        }
        for(int i=1;i<=n;i++){
            bool b = true;
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                if(mp[j][i]==0 || mp[i][j]==1){
                    b = false;
                    break;
                }
            }
            if(b && mp[i][i]==0){
                return i;
            }
        }
        return -1;
    }
};