class Solution {
public:
    int minPartitions(string n) {
       int ans = 0;
        for(auto ch : n){
            int val = ch-'0';
            ans = max(ans,val);
        }
        return ans;
    }
};