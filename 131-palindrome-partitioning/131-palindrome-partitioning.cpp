class Solution {
public:
    vector<vector<string>> ans;
    vector<string> st;
    bool isPalindrome(string &st,int s,int e){
        while(s<e){
            if(st[s++]!=st[e--]) return false;
        }
        return true;
    }
    void solve(string& s,int ind){
        if(ind==s.size()){
            ans.push_back(st);
            return ;
        }
        
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                st.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1); 
                st.pop_back();
            } 
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};