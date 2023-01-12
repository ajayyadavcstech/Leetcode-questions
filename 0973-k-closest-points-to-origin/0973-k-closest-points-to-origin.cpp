class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(auto &x:points){
            pq.push({x[0]*x[0]+x[1]*x[1],x[0],x[1]});
        }
        while(k--){
            vector<int> t = pq.top();
            pq.pop();
            ans.push_back({t[1],t[2]});
        }
        return ans;
    }
};