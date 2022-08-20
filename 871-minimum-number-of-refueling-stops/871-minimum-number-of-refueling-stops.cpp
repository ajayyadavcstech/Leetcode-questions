class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int cnt = 0;
        int pos = 0;
        int fuel = startFuel;
        stations.push_back({target,0});
        for(int i=0;i<stations.size();i++){
            if(pos+fuel>=stations[i][0]){
                fuel = fuel - (stations[i][0]-pos);
                pos = stations[i][0];
                pq.push(stations[i][1]);
            }
            else if(pq.size()){
                fuel += pq.top();
                cnt++;
                pq.pop();
                i--;
            }
            else return -1;
        }
        return cnt;
    }
};