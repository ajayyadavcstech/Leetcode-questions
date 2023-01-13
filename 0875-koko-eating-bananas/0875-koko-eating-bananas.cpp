class Solution {
public:
    bool solve(vector<int>&piles,double speed,int hour){
        int total_hour = 0;
        for(auto &x:piles){
            int h = ceil(x/speed);
            if(h+total_hour>hour) return false;
            total_hour+=h;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0;
        for(auto &x:piles){
            mx = max(mx,x);
        }
        int s = 1;
        int e = mx;
        int ans = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(solve(piles,mid,h)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};