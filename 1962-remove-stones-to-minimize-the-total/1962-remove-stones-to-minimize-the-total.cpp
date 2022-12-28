class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto &x:piles) pq.push(x);
        while(k--){
            int val = pq.top();
            pq.pop();
            pq.push(val-val/2);
        }
        int ans = 0;
        while(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};