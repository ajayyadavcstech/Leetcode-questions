class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT32_MAX;
        for(auto x:nums){
            if(x&1) x*=2;
            pq.push(x);
            mn = min(mn,x);
        }
        int ans =  pq.top()-mn;
        while((pq.top()&1)==0){
            int x = pq.top()/2;
            pq.push(x);
            pq.pop();
            mn = min(mn,x);
            ans = min(ans,pq.top()-mn);
        }
        return ans;
    }
};