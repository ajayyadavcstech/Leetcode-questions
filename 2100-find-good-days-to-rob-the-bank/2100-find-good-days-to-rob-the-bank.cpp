class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> dec(n,0);
        vector<int> inc(n,0);
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1]) dec[i]+=(dec[i-1]+1);
        }
        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]) inc[i]+=(inc[i+1]+1);
        }
        for(int i=0;i<n;i++){
            int cnt = min(dec[i],inc[i]);
            if(cnt>=time) ans.push_back(i);
        }
        return ans;
    }
};