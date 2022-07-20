class Solution {
public:
    bool isSubseq(string &s,string word){
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==word[j]) j++;
            if(j==word.size()) return true;
        }
        return j==word.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        int ans=0;
        for(auto x : words) mp[x]++;
        for(auto [key,value]:mp){
            if(isSubseq(s,key)) ans+=value;
        }
        return ans;
    }
};