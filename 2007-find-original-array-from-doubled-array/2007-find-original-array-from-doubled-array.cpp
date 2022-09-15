class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto x : changed){
            if(!(x&1) && mp.find(x/2)!=mp.end()){
                v.push_back(x/2);
                mp[x/2]--;
                if(mp[x/2]==0) mp.erase(x/2);
            }
            else if(mp.find(2*x)!=mp.end()){
                v.push_back(x);
                mp[x*2]--;
                if(mp[x*2]==0) mp.erase(x*2);
            }
            else {
                mp[x]++;
            }
        }
        return ((changed.size()&1 || v.size()!=changed.size()/2) ? vector<int>() : v);
    }
};