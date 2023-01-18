class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int mx_sum = INT32_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(sum<0){
                sum = nums[i];
            }
            else sum+=nums[i];
            mx_sum = max(sum,mx_sum);
        }
        vector<int> left(n),right(n);
        sum = nums[0];
        left[0] = 0;
        for(int i=1;i<n;i++){
            left[i] = max(sum,left[i-1]);
            sum+=nums[i];
        }
        sum = nums[n-1];
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            sum+=nums[i];
            right[i] = max(sum,right[i+1]);
        }
        for(int i=0;i<n;i++){
            mx_sum = max(mx_sum,left[i]+right[i]);
        }
        return mx_sum;
    }
};