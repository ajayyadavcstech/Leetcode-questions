class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind = nums.size();
        int i=0;
        int j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]>=target){
                ind = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return ind;
    }
};