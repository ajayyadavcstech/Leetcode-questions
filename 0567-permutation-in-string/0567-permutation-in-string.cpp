class Solution {
public:
    bool is_substr(vector<int>&mp1,vector<int>&mp2){
        for(int i=0;i<26;i++) if(mp1[i]!=mp2[i]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(auto &x:s1) mp1[x-'a']++;
        for(int i=0;i<s2.size();i++){
            mp2[s2[i]-'a']++;
            if(i>=s1.size()-1){
                if(is_substr(mp1,mp2)) return true;
                mp2[s2[i-s1.size()+1]-'a']--;
            }
        }
        return false;
    }
};