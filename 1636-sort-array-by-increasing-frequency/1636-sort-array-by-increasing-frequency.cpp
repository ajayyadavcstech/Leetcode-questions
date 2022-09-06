class Solution {
public:
    static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second==p2.second ? p1.first>p2.first : p1.second<p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums) mp[x]++;
        vector<pair<int,int>> v;
        vector<int> ans;

        for(auto x : mp) v.push_back({x.first,x.second});
        sort(v.begin(),v.end(),comp);
        for(auto x : v){
            while(x.second--) ans.push_back(x.first);
        }
        return ans;
    }
};