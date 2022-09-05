class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            while(!(nums[i]&1) && i<j) i++;
            while((nums[j]&1) && i<j) j--;
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};