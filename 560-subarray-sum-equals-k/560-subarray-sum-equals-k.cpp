class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> prefix(nums.size());
        unordered_map<int,int> mp;
        mp[0] = 1;
        prefix[0] = nums[0];
        if(nums[0]==k) ans++;
        mp[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i];
            if(mp.find(prefix[i]-k)!=mp.end()){
                ans+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};