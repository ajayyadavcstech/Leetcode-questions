class Solution {
public:
    int solve(vector<int> &v){
        int first = 0;
        int second = 0;
        for(int i=0;i<v.size();i++){
           if(v[i]>first){
               second = first;
               first = v[i];
           } 
            else if(v[i]>second) second = v[i];
        }
        return first+second;
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