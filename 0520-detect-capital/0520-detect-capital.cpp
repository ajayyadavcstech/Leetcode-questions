class Solution {
public:
    bool all_cap(string&s){
        for(int i=0;i<s.size();i++) if(!(s[i]>='A' && s[i]<='Z')) return false;
        return true;
    }
    bool all_small(string&s){
        for(int i=0;i<s.size();i++) if(!(s[i]>='a' && s[i]<='z')) return false;
        return true;
    }
    bool cap_small(string&s){
        if(!(s[0]>='A' && s[0]<='Z')) return false;
        for(int i=1;i<s.size();i++) if(!(s[i]>='a' && s[i]<='z')) return false;
        return true;
    }
    bool detectCapitalUse(string word) {
        return all_cap(word) || all_small(word) || cap_small(word);
    }
};