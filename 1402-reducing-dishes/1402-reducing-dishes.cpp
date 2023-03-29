class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end(),greater<int>());
        int ans = 0;
        int cur_sum = 0;
        for(int i=0;i<sat.size();i++){
            cur_sum+=sat[i];
            if(cur_sum<=0) break;
            ans+=cur_sum;
        }
        return ans;
    }
};