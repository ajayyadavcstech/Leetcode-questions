class comp{
  public:
    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        return p1.first<p2.first;
    }
};
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        for(int i=0;i<growTime.size();i++){
            pq.push({growTime[i],i});
        }
        int mxPlantTime = 0;
        int mxGrowTime = 0;
        while(pq.size()){
            pair<int,int> p = pq.top();
            mxPlantTime+=plantTime[p.second];
            mxGrowTime = max(mxGrowTime,mxPlantTime+p.first);
            pq.pop();
        }
        return mxGrowTime;
    }
};