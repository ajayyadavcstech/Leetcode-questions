class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int mx = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mx) cnt++;
            else cnt--;
            if(cnt==-1) {
                cnt = 1;
                mx = nums[i];
            }
        }
        return mx;
    }
};