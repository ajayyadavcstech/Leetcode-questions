class Solution {
public:
    bool check(string&st){
        int s = 0;
        int e = st.size()-1;
        while(s<e){
            if(st[s]!=st[e]) return false;
            s++;e--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string st;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                char ch = s[i]>='A' && s[i]<='Z' ? s[i]+32 : s[i];
                st.push_back(ch);
            }
        }
        return check(st);
    }
};