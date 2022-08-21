class Solution {
public:
    bool ismatch(string &s1,string &s2){
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i] && s1[i]!='?' && s2[i]!='?') return false;
        }
        return true;
    }
    bool isQue(string &s){
        for(int i=0;i<s.size();i++){
            if(s[i]!='?') return false;
        }
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        bool check = true;
        while(check){
            check = false;
            for(int i=0;i<=target.size()-stamp.size();i++){
                string str = target.substr(i,stamp.size());
                if(isQue(str)) continue;
                if(ismatch(str,stamp)) {
                    check=true;
                    ans.push_back(i);
                    if(ans.size()>target.size()*10) return {};
                    for(int j = i;j<i+stamp.size();j++) target[j] = '?';
                }
            }
        }
        if(!isQue(target)) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};