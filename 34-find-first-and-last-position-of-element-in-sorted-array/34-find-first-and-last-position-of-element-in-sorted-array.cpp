class Solution {
public:
    int lower_bound(vector<int>&nums,int target){
        int ind = -1;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s + (e - s)/2;
            if(nums[mid]==target){
                ind = mid;
                e = mid-1;
            }
            else if(nums[mid]>target) e = mid - 1;
            else s = mid + 1;
        }
        return ind;
    }
     int Upper_bound(vector<int>&nums,int target){
        int ind = -1;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s + (e - s)/2;
            if(nums[mid]==target){
                ind = mid;
                s = mid + 1;
            }
            else if(nums[mid]>target) e = mid - 1;
            else s = mid + 1;
        }
        return ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(nums,target),Upper_bound(nums,target)};
    }
};