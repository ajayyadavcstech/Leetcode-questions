class Solution {
public:
    vector<string> ans;
    string st;
    void solve(string &s,int ind){
        if(ind==s.size()){
            ans.push_back(st);
            return ;
        }
        
        if(s[ind]>='0' && s[ind]<='9'){
            st.push_back(s[ind]);
            solve(s,ind+1);
            st.pop_back();
        }
        else{
            st.push_back(toupper(s[ind]));
            solve(s,ind+1);
            st.pop_back();

            st.push_back(tolower(s[ind]));
            solve(s,ind+1);
            st.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,0);
        return ans;
    }
};