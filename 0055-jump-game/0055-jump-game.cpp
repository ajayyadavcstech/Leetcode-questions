class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        int step = nums[0];
        int n = nums.size();
        step--;
        for(int i=1;i<n;i++){
            step = max(step,nums[i]);
            if(step==0 && i!=n-1) return false;
            step--;
        }
        return true;
    }
};