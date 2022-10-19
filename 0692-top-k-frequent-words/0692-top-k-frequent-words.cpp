class comp{
    public:
    bool operator()(pair<string,int>&a,pair<string,int>&b){
        if(a.second!=b.second) return a.second>b.second;
        else return a.first<b.first;
    }  
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &x:words) mp[x]++;
        priority_queue<pair<string,int>,vector<pair<string,int>>,comp> pq;
        int cnt = 0;
        for(auto &x:mp){
            if(cnt<k){
                cnt++;
                pq.push(x);
            }
            else if(pq.top().second<x.second || (pq.top().second==x.second && pq.top().first>x.first)){
                pq.pop();
                pq.push(x);
            }
        }
        vector<string> ans;
        while(pq.size()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};