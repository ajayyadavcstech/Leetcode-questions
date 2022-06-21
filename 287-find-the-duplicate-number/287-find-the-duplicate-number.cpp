class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto i : nums){
            int ind = abs(i);
            if(nums[ind]<0) return ind;
            nums[ind] = -nums[ind];
        }
        return -1;
    }
};