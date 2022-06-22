class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int k = 0;
        while(k<=j){
            if(nums[k]==0) {
                swap(nums[k++],nums[i++]);
            }
            else if(nums[k]==1) k++;
            else{
                swap(nums[k],nums[j--]);
            }
        }
    }
};