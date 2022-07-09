class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
            while(i-pq.top().second>k){
                pq.pop();
            }
            cout<<pq.top().first<<" ";
            dp[i] = pq.top().first + nums[i];
            pq.push({dp[i],i});
        }
        return dp[nums.size()-1];
    }
};