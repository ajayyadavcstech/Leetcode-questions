class Solution {
public:
    int solve(vector<int>&nums,int i,int j,int val,int target){
        int ans = 100000000;
        while(i<j){
            int sum = val + nums[i] + nums[j] ;
            ans = abs(target-ans)<abs(target-sum) ? ans : sum;
            if(sum<target) i++;
            else j--;
        }
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 100000000;
        for(int i=0;i+2<nums.size();i++){
            int cur = solve(nums,i+1,nums.size()-1,nums[i],target);
            ans = abs(target-cur)<abs(target-ans) ? cur : ans;
        }
        return ans;
    }
};