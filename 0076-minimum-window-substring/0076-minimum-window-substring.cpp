class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_mp,s_mp;
        for(auto &x:t) t_mp[x]++;
        vector<pair<char,int>> v;
        for(int i=0;i<s.size();i++){
            if(t_mp.count(s[i])){
                v.push_back({s[i],i});
            }
        }
        int i = 0;
        int j = 0;
        string ans;
        int cnt = 0;
        while(j<v.size() || i<v.size()){
            if(cnt<t.size() && j<v.size()){
                pair<int,int> p = v[j];
                s_mp[p.first]++;
                if(s_mp[p.first]<=t_mp[p.first]) cnt++;
                j++;
            }
            else if(cnt==t.size()){
                int cur_size = v[j-1].second - v[i].second+1;
                ans = ((ans.size()>cur_size) || ans.size()==0 )? s.substr(v[i].second,cur_size) : ans;
                pair<int,int> p = v[i];
                s_mp[p.first]--;
                if(s_mp[p.first]<t_mp[p.first]) cnt--;
                i++;
            }
            else i++;
        }
        
        return ans;
    }
};