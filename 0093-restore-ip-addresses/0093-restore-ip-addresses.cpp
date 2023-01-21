class Solution {
public:
    vector<string> ans;
    void solve(string &s,string str="",string num="",int cnt=4,int ind=0){
        if(ind==s.size()){
            if(cnt==0){
                str.pop_back();
                ans.push_back(str);
            }
            return ;
        }
        if(cnt==0) return ;
        num.push_back(s[ind]);
        if(stoi(num)>255) return ;
        else if(stoi(num)==0)  solve(s,str+num+'.',"",cnt-1,ind+1);
        else{
            solve(s,str,num,cnt,ind+1);
            solve(s,str+num+'.',"",cnt-1,ind+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>12) return {};
        solve(s);
        return ans;
    }
};