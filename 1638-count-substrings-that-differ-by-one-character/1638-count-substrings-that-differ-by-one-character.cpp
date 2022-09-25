class Solution {
public:
    int countSubstrings(string s, string t) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                int m = i;
                int n = j;
                int cur_cnt = 0;
                while(m<s.size() && n<t.size()){
                    if(s[m]!=t[n]) cur_cnt++;
                    if(cur_cnt>1) break;
                    m++;
                    n++;
                    if(cur_cnt==1) count++;
                }
            }
        }
        return count;
    }
};