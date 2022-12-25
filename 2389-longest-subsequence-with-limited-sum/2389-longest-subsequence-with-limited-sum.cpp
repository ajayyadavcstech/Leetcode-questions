class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        vector<int> sum;
        long long cur_sum = 0;
        for(auto &x:nums){
            cur_sum+=x;
            sum.push_back(cur_sum);
        }
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            auto pt = upper_bound(sum.begin(),sum.end(),q[i]);
            int val = pt - sum.begin();
            ans.push_back(val);
        }
        return ans;
    }
};