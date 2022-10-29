class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(pq.size() && pq.top()[0]<nums[i]){
                ans[pq.top()[1]] = nums[i];
                pq.pop();
            }
            pq.push({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
           while(pq.size() && pq.top()[0]<nums[i]){
                ans[pq.top()[1]] = nums[i];
                pq.pop();
            }
        }
        return ans;
    }
};