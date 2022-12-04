class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(auto &x:nums) sum+=x;
        int ind = 0;
        int mn = INT32_MAX;
        long long cur = 0;
        for(int i=0;i<n-1;i++){
            cur+=nums[i];
            int mid = abs(cur/(i+1) - (sum-cur)/(n-i-1));
            if(mid<mn){
                mn = mid;
                ind = i;
            }
        }
        if((sum/n)<mn) return n-1;
        return ind;
    }
};