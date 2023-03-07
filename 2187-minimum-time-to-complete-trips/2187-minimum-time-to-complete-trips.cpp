class Solution {
public:
    bool solve(long long total_time,vector<int> &time,int totalTrips){
        long long total_round = 0;
        for(int i=0;i<time.size();i++){
            long long round = total_time/time[i];
            total_round+=round;
            if(total_round>totalTrips) return true;
            if(round==0) break;
        }
        return totalTrips<=total_round;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long s = 1;
        long long e = 10e15;
        long long ans = -1;
        while(s<=e){
            long long mid = s + (e-s)/2;
            if(solve(mid,time,totalTrips)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};