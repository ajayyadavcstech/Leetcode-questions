class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> mp;
        for(auto x : magazine) mp[x]++;
        for(auto x : ransomNote){
            if(mp.count(x)>0){
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
            }
            else return false;
        }
        return true;
    }
};