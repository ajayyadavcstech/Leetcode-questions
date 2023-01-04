class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,float> mp;
        for(auto &x:tasks){
            mp[x]++;
        }
        int cnt = 0;
        for(auto &x:mp){
            if(x.second==1) return -1;
            cnt+=ceil(x.second/3);
        }
        return cnt;
    }
};