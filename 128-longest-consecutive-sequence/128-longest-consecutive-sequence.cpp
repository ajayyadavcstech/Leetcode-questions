class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto x : nums){
            mp[x] = true;
        }
        for(auto x : nums){
            if(mp.find(x-1)!=mp.end()){
                mp[x] = false;
            }
        }
        int ans = 0;
        for(auto x : nums){
            int cur = 0;
            if(mp[x]){
                while(mp.find(x)!=mp.end()) {
                    cur++;
                    x++;
                }
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};