class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mn = 1;
        int i = 0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]-nums[i]>k){
                mn++;
                i = j;
            }
        }
        return mn;
    }
};