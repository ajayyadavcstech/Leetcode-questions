class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx_val = 0;
        int ans = 0;
        for(auto &x:nums) mx_val = max(mx_val,x);
        int cur = 0;
        for(auto &x:nums){
            if(x==mx_val) {
                cur++;
                ans = max(cur,ans);
            }
            else cur = 0;
        }
        return ans;
    }
};