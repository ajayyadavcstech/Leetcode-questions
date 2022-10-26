class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int cur = 0;
        for(int i=0;i<nums.size();i++){
            cur = (cur+nums[i])%k;
            if(mp.count(cur) && mp[cur]!=i-1) return true;
            if(!mp.count(cur)) mp[cur] = i;
        }
        return false;
    }
};