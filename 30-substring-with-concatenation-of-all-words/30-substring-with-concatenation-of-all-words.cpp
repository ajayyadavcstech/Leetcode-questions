class Solution {
public:
    bool Valid(string s,unordered_map<string,int> mp,int n){
        int i = 0;
        while(i<s.size()){
            string st = s.substr(i,n);
            if(mp.find(st)!=mp.end()){
                mp[st]--;
                i+=n;
                if(mp[st]==-1) return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> mp;
        for(auto x : words){
            mp[x]++;
        }
        int words_len = words.size();
        int n = s.size();
        int total_len = words[0].size()*words_len;
        for(int i = 0 ;(i+total_len-1)<s.size();i++){
            if(Valid(s.substr(i,total_len),mp,words[0].size())) ans.push_back(i);
        }
        return ans;
    }
};