class Solution {
public:
    class comp{
        public:
        bool operator()(pair<int,int>&p1,pair<int,int>&p2){
            if(p1.second!=p2.second) return(p1.second > p2.second);
            else return p1.first > p2.first;
        }  
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        vector<int> v;
        for(auto &val:arr){
            pair<int,int> p;
            p.first = val;
            p.second = abs(val-x);
            pq.push(p);
        }
        for(int i=0;i<k;i++){
            v.push_back(pq.top().first);
            pq.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};