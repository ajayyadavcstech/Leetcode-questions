class Solution {
public:
    bool solve(string s,string &str1,string&str2){
        if(str1.size()%s.size()!=0 || str2.size()%s.size()!=0) return false;
        int i = 0;
        for(i=0;i<str1.size();){
            for(int j=0;j<s.size();j++,i++){
                if(str1[i]!=s[j] || str2[i]!=s[j]) return false;
            }
        }
        for(;i<str2.size();){
            for(int j=0;j<s.size();j++,i++){
                if(str2[i]!=s[j]) return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()>str2.size()) return gcdOfStrings(str2,str1);
        string ans = "";
        string temp = "";
        for(int i=0;i<str1.size();i++){
            temp.push_back(str1[i]);
            if(solve(temp,str1,str2)) ans = temp;
        }
        return ans;
    }
};