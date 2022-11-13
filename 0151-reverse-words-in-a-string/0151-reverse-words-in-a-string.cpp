class Solution {
public:
    string reverseWords(string s) {
        string str;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && str.size()) {
                ans = str + " " + ans;
                str = "";
            } 
            else if(s[i]!=' ') str.push_back(s[i]);
        }
         if(str.size()) ans = str + " " + ans;
        ans.pop_back();
        return ans;
    }
};