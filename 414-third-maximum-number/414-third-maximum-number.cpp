class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = INT64_MIN;
        long second = INT64_MIN;
        long third = INT64_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>first) first = nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=first && nums[i]>second) second = nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=first && nums[i]!=second && nums[i]>third) third = nums[i];
        }
        return third==INT64_MIN ? max({first,second,third}) : third;
    }
};