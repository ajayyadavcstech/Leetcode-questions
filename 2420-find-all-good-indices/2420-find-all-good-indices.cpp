class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> left(nums.size(),1),right(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]) left[i] = left[i-1]+1;
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) right[i] = right[i+1]+1;
        }
        vector<int> ans;
        for(int i=k;i<nums.size()-k;i++){
            if(left[i-1]>=k && right[i+1]>=k) ans.push_back(i);
        }
        return ans;
    }
};