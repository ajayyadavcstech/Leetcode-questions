class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> cap_pro;
        int n = profits.size();
        for(int i=0;i<n;i++){
            cap_pro.push_back({capital[i],profits[i]});
        }
        sort(cap_pro.begin(),cap_pro.end());
        priority_queue<int> pq;
        int i = 0;
        for(int j=0;j<k;j++){
            while(i<n && cap_pro[i].first<=w){
                pq.push(cap_pro[i].second);
                i++;
            }
            if(pq.size()==0) return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};