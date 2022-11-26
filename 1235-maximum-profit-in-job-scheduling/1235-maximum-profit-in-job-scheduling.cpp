class Solution {
public:
    int binary_search(vector<vector<int>>&num,int s,int e,int x){
        int ans = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(num[mid][0]<=x){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> num;
        int n = profit.size();
        for(int i=0;i<n;i++){
            num.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(num.begin(),num.end());
        vector<int> dp(n,0);
        dp[0] = num[0][2];
        for(int i=1;i<n;i++){
            int ind = binary_search(num,0,i-1,num[i][1]);
            if(ind==-1) dp[i] = max(dp[i-1],num[i][2]);
            else dp[i] = max(dp[i-1],dp[ind]+num[i][2]);
        }
        return dp[n-1];
    }
};