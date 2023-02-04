class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        int cnt = 0;
        for(auto &x:s1) mp1[x-'a']++;
        for(int i=0;i<s2.size();i++){
            int ind = s2[i]-'a';
            mp2[ind]++;
            if(mp2[ind]<=mp1[ind]) cnt++;
            if(i>=s1.size()-1){
                if(cnt==s1.size()) return true;
                ind = s2[i-s1.size()+1]-'a';
                mp2[ind]--;
                if(mp2[ind]<mp1[ind]) cnt--;
            }
        }
        return false;
    }
};