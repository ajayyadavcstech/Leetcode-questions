class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = "";
        int cnt = 1;
        string str = countAndSay(n-1);
        for(int i=1;i<str.size();i++){
            if(str[i]==str[i-1]) cnt++;
            else {
                ans = ans + to_string(cnt);
                ans.push_back(str[i-1]);
                cnt = 1;
            }
        }
        ans = ans + to_string(cnt);
        ans.push_back(str[str.size()-1]);
        return ans;
    }
};