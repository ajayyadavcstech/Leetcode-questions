class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return nums[0];
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            int pre = mid==0 ? INT32_MIN : nums[mid-1];
            int next = mid==n-1 ? INT32_MAX : nums[mid+1];
            if(nums[mid]!=pre && nums[mid]!=next) return nums[mid];
            else if((mid%2==0 && nums[mid]==next) || (mid&1 && nums[mid]==pre)) s = mid+1;
            else e = mid-1;
        }
        return -1;
    }
};