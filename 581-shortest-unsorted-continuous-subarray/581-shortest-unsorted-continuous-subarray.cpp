class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans = 0;
        int max = nums[0];
        int j=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=max) max = (max>nums[i]?max:nums[i]);
            else{
                if(ans==0) j = i-1;
                while(j!=-1 && nums[j]>nums[i]) j--;
                ans = ((ans>i-j )? ans : i-j);
            }
        }
        return ans;
    }
};