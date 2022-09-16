class Solution {
public:
    string st;
    unordered_set<string> mp;
    int n = 0;
    void solve(string &s,int ind,int open,int close){
        if(ind==s.size()){
            if(open!=close) return ;
            if(st.size()>n){
                mp.clear();
                mp.insert(st);
                n = st.size();
            }
            else if(st.size()==n) mp.insert(st);
            return ;
        }
        
        if(s[ind]>='a' && s[ind]<='z'){
            st.push_back(s[ind]);
            solve(s,ind+1,open,close);
            st.pop_back();
        }
        else if(s[ind]=='('){
            solve(s,ind+1,open,close);
            st.push_back('(');
            solve(s,ind+1,open+1,close);
            st.pop_back();
        }
        else{
            solve(s,ind+1,open,close);
            if(open>close){
                st.push_back(')');
                solve(s,ind+1,open,close+1);
                st.pop_back();
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s,0,0,0);
        return vector<string>(mp.begin(),mp.end());
    }
};