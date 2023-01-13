class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<float>> carInfo;
        int n = position.size();
        for(int i=0;i<n;i++){
            float time = (float(target-position[i]))/speed[i];
            carInfo.push_back({(float)position[i],time});
        }
        sort(carInfo.begin(),carInfo.end(),greater<vector<float>>());
        float time = carInfo[0][1];
        int fleet = 1;
        for(int i=1;i<n;i++){
            if(carInfo[i][1]>time) {
                fleet++;
                time = carInfo[i][1];
            }
        }
        return fleet;
    }
};