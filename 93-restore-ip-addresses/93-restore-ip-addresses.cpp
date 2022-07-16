class Solution {
public:
    vector<string> ans;
    void solve(string &s,int i=0,int n=1,string temp=""){
        if(n==5 && i==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return ;
        }
        if(s[i]=='0'){
            solve(s,i+1,n+1,temp+s.substr(i,1)+".");
            return ;
        }
       if(i<s.size()){
           solve(s,i+1,n+1,temp+s.substr(i,1)+".");
       }
       if(i+1<s.size()){
           solve(s,i+2,n+1,temp+s.substr(i,2)+".");
       }
       if(i+2<s.size() && stoi(s.substr(i,3))<=255){
           solve(s,i+3,n+1,temp+s.substr(i,3)+".");
       }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>12) return ans;
        solve(s);
        return ans;
    }
};