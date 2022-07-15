class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        for(auto &ch:s){
            mp[ch] ++;
        }
        string ans;
        vector<bool> visited(26,false);
        for(auto &x : s){
            if(visited[x-'a']) {
                mp[x]--;
                continue;
            }
            while(ans.size()!=0 && x<ans[ans.size()-1] && mp[ans[ans.size()-1]]>0){
                visited[ans[ans.size()-1]-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(x);
            visited[x-'a']=true;
            mp[x]--;
        }
        return ans;
    }
};