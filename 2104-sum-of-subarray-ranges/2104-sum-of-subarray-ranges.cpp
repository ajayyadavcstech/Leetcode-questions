class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            int max = INT32_MIN;
            int min = INT32_MAX;
            for(int j=i;j<nums.size();j++){
                max = max<nums[j]?nums[j]:max;
                min = min>nums[j]?nums[j]:min;
                ans +=(max-min);
            }
        }
        return ans;
    }
};