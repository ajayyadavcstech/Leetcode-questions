class Solution {
public:
    vector<int> dp;
    int mod = 1000000007;
    long solve(vector<int>&arr,int ind){
        if(ind==-1) return 0; 
        if(dp[ind]!=-1) return dp[ind];
        long cnt = 1;
        int s = 0;
        int e = ind-1;
        while(s<=e){
            long mul = (long)arr[s]*arr[e];
            if(mul==arr[ind]){
                long temp = (solve(arr,s) * solve(arr,e))%mod;
                if(s!=e) temp=temp*2;
                cnt = (cnt+temp)%mod;
                s++;
                e--;
            }
            else if(mul>arr[ind]) e--;
            else s++;
        }
        return dp[ind] = cnt;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
       sort(arr.begin(),arr.end());
      dp.resize(arr.size(),-1);
        long cnt = 0;
        for(int i=0;i<arr.size();i++){
            cnt=(cnt+solve(arr,i))%mod;
        }
        return cnt;
    }
};