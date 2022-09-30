class Solution {
public:
    int solve(vector<int> &v){
        sort(v.begin(),v.end(),greater<int>());
        return v[0]+v[1];
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int max_sum = -1;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int sum = 0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            mp[sum].push_back(nums[i]);
        }
        for(auto &x : mp){
            if(x.second.size()>1) max_sum = max(max_sum,solve(x.second));
        }
        return max_sum;
    }
};