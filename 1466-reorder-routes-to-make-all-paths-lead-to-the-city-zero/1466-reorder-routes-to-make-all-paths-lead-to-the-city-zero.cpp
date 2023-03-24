class Solution {
public:
    void CountReorderRoad(int node,unordered_map<int,unordered_set<int>> &TwoWay,unordered_map<int,unordered_set<int>> &OneWay,int par,int &ans){
        for(auto &x:TwoWay[node]){
            if(x==par) continue;
            if(OneWay[node].count(x)) ans++;
            CountReorderRoad(x,TwoWay,OneWay,node,ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& adj) {
        unordered_map<int,unordered_set<int>> TwoWay;
        unordered_map<int,unordered_set<int>> OneWay;
        for(auto &x:adj){
            TwoWay[x[0]].insert(x[1]);
            TwoWay[x[1]].insert(x[0]);
            OneWay[x[0]].insert(x[1]);
        }
        int ans = 0;
        CountReorderRoad(0,TwoWay,OneWay,-1,ans);
        return ans;
    }
};