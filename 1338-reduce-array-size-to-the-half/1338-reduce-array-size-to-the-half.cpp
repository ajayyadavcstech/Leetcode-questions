class Solution {
public:
    static bool comp(pair<int,int> &p1,pair<int,int> &p2){
        return p1.second>p2.second;
    }
    int minSetSize(vector<int>& arr) {
        cout<<arr.size()<<endl;
        map<int,int> mp;
        for(auto x : arr) mp[x]++;
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),comp);
        int total = 0;
        int i = 0;
        while(total<arr.size()/2){
            total+=v[i].second;
            i++;
        }
        return i;
    }
};