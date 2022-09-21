class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even_sum = 0;
        vector<int> ans;
        for(auto &x : nums) if(!(x&1)) even_sum+=x;
        for(auto &x : queries){
            int ind = x[1];
            int val = x[0];
            
            if(nums[ind]%2==0){
                if(val%2==0) even_sum+=val;
                else even_sum-=nums[ind];
            }
            else{
                if(val%2!=0) even_sum+=(nums[ind]+val);
            }
            nums[ind]+=val;
            ans.push_back(even_sum);
        }
        return ans;
    }
};