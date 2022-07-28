class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mp;
        for(auto x:s) mp[x]++;
        for(auto x:t){
            if(mp.find(x)==mp.end()) return false;
            mp[x]--;
            if(mp[x]==0) mp.erase(x);
        }
        return true;
    }
};