class Solution {
public:
    unordered_set<string> mp;
    void solve(int n,string s){
        if(!n){
            mp.insert(s);
            return ;
        }
        
        for(int i=0;i<=s.size();i++){
            string st = s.substr(0,i) + "()" + s.substr(i,s.size()-i);
            solve(n-1,st);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,"");
        return vector<string>(mp.begin(),mp.end());
    }
};