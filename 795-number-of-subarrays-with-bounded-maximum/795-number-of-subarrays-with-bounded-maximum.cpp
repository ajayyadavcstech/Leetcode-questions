class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int j=-1;
        int sub = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>right){
                j = i;
                sub = 0;
            }
            else if(nums[i]<left){
                sub++;
            }
            else sub = 0;
            ans = ans + i - j - sub;
        }
        return ans;
    }
};