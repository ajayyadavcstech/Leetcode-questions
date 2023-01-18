class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx_sum = INT32_MIN;
        for(auto &x:nums){
            sum = max(x,sum+x);
            mx_sum = max(mx_sum,sum);
        }
        return mx_sum;
    }
};