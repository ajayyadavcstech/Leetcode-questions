class Solution {
public:
    static bool comp(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0] && v1[2]==1 && v2[2]==1){
            
            return v1[1]>v2[1];
        }
        else if(v1[2]==-1 && v2[2]==-1 && v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        else if((v1[2]==-1 && v2[2]==1 && v1[0]==v2[0]) || (v1[2]==1 && v2[2]==-1 && v1[0]==v2[0])){
            return v1[2]>v2[2];
        }
        else return v1[0]<v2[0];
        return true;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>> v;
        vector<vector<int>> ans;
        map<int,int> mp;
        mp[0]++;
        for(int i=0;i<b.size();i++){
            v.push_back({b[i][0],b[i][2],1});
            v.push_back({b[i][1],b[i][2],-1});
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++){
            vector<int> &temp = v[i];
            if(temp[2]==1){
                int before = mp.rbegin()->first;
                mp[temp[1]]++;
                int after = mp.rbegin()->first;
                if(before!=after) ans.push_back({temp[0],after});
            }
            else {
                int before = mp.rbegin()->first;
                mp[temp[1]]--;
                if(mp[temp[1]]==0) mp.erase(temp[1]);
                int after = mp.rbegin()->first;
                if(before!=after) ans.push_back({temp[0],after});
            }
        }
        return ans;
    }
};