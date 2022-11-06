class Solution {
public:
    string solve_for_1(string &s){
        string ans = s;
        for(int i=0;i<s.size();i++){
            string temp = s.substr(i+1,s.size()-i-1) + s.substr(0,i-0+1);
            ans = ans>temp ? temp : ans;
        }
        return ans;
    }
    string orderlyQueue(string s, int k) {
        if(k==1) return solve_for_1(s);
        sort(s.begin(),s.end());
        return s;
    }
};