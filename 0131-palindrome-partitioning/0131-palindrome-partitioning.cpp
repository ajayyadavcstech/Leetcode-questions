class Solution {
public:
    bool isPalindrome(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    vector<vector<string>> ans;
    vector<string> v;
    void solve(string &s,int ind=0){
        if(ind==s.size()){
            ans.push_back(v);
            return ;
        }
        string str;
        for(int i=ind;i<s.size();i++){
            str.push_back(s[i]);
            if(isPalindrome(str)){
                v.push_back(str);
                solve(s,i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s);
        return ans;
    }
};