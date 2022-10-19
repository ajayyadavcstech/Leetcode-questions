class comp{
    public:
    bool operator()(pair<string,int>&a,pair<string,int>&b){
        if(a.second!=b.second) return a.second<b.second;
        else return a.first>b.first;
    }  
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &x:words) mp[x]++;
        priority_queue<pair<string,int>,vector<pair<string,int>>,comp> pq;
        int cnt = 0;
        for(auto &x:mp) pq.push(x);
        vector<string> ans;
        while(k>0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};