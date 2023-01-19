class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt = 0;
        int sum = 0;
        mp[0]++;
        for(auto &x:nums){
            sum+=(x%k)+k;
            cnt+=mp[sum%k];
            mp[sum%k]++;
        }
        return cnt;
    }
};