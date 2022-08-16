class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            mp[ch].first++;
            mp[ch].second = i;
        }
        int ind = INT32_MAX;
        for(auto x : mp){
            pair<int,int> temp = x.second;
            if(temp.first==1) ind = min(ind,temp.second);
        }
        return ind==INT32_MAX ? -1 : ind;
    }
};