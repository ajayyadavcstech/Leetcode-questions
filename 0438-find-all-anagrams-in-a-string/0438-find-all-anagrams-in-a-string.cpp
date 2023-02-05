class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp1(26,0);
        for(auto&x:p) mp1[x-'a']++;
        vector<int> mp2(26,0);
        vector<int> ans;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            int ind = s[i]-'a';
            mp2[ind]++;
            if(mp2[ind]<=mp1[ind]) cnt++;
            
            if(i>=p.size()-1){
                ind = s[i-p.size()+1]-'a';
                if(cnt==p.size()) ans.push_back(i-p.size()+1);
                mp2[ind]--;
                if(mp2[ind]<mp1[ind]) cnt--;
            }
        }
        return ans;
    }
};