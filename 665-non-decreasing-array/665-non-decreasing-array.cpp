class Solution {
public:
    bool isIncresing(vector<int>&nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                int pre = nums[i];
                nums[i] = nums[i+1];
                bool b1 = isIncresing(nums);
                nums[i] = nums[i+1] = pre;
                bool b2 = isIncresing(nums);
                return b1 || b2;
            }
        }
        return true;
    }
};