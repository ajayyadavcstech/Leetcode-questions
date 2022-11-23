class Solution {
public:
    void count(vector<int>&left,vector<int>&right,string &s,char x){
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            left[i] = cnt;
            if(s[i]==x) cnt++;
        }
        cnt = 0;
        for(int i=s.size()-1;i>=0;i--){
            right[i] = cnt;
            if(s[i]==x) cnt++;
        }
    }
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> left(n),right(n);
        long long ans = 0;
        count(left,right,s,'1');
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans = ans + ((long)left[i]*right[i]);
            }
        }
        count(left,right,s,'0');
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans = ans + ((long)left[i]*right[i]);
            }
        }
        return ans;
    }
};