class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto &x:s) mp[x]++;
        vector<vector<int>> fre;
        for(auto &x:mp) fre.push_back({x.second,x.first});
        sort(fre.begin(),fre.end());
        string ans;
        for(auto &x:fre){
            int n = x[0];
            while(n--) ans.push_back(x[1]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};