class Solution {
public:
    bool solve(int k,vector<int>&piles,int h){
        int hour = 0;
        for(int i=0;i<piles.size();i++){
            double pile = piles[i];
            double cur_hour = pile/k;
            hour+=ceil(cur_hour);
            if(hour>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 1e9;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(solve(mid,piles,h)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};