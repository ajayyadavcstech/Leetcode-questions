class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        int mx_sum = INT32_MIN;
        int mn_sum = INT32_MAX;
        int total = 0;
        for(auto &x:nums){
            total+=x;
            if(sum1<0) sum1 = x;
            else sum1+=x;
            if(sum2>0) sum2 = x;
            else sum2+=x;
            mx_sum = max(mx_sum,sum1);
            mn_sum = min(mn_sum,sum2);
        }
        return total==mn_sum ? mx_sum : max(total-mn_sum,mx_sum);
    }
};