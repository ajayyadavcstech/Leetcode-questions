class Solution {
public:
    char isMatch(char ch){
        if(ch>='a' && ch<='z') return 'A' + (ch-'a');
        return 'a' + (ch-'A');
    }
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0 || st.top()!=isMatch(s[i])) st.push(s[i]);
            else st.pop();
        }
        string ans;
        while(st.size()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};