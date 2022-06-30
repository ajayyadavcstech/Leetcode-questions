class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums[nums.size()/2];
        int Step = 0;
        for(auto &val : nums){
            Step += abs(val-mid);
        }
        return Step;
    }
};