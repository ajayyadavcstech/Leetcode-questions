class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int top_count = 1;
        int bottom_count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) top_count = bottom_count+1;
            if(nums[i]<nums[i-1]) bottom_count = top_count + 1;
        }
        return max(top_count,bottom_count);
    }
};