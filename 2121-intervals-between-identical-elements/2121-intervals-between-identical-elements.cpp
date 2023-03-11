class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n),right(n);
        unordered_map<int,vector<long long>> mp1;
        for(int i=0;i<arr.size();i++){
            if(mp1.count(arr[i])==0) mp1[arr[i]] = {i,0,0};
            left[i] = mp1[arr[i]][2] + (i-mp1[arr[i]][0])*mp1[arr[i]][1];
            mp1[arr[i]] = {i,++mp1[arr[i]][1],left[i]};
        }
        mp1.clear();
        for(int i=n-1;i>=0;i--){
            if(mp1.count(arr[i])==0) mp1[arr[i]] = {i,0,0};
            right[i] = mp1[arr[i]][2] + (mp1[arr[i]][0]-i)*mp1[arr[i]][1];
            mp1[arr[i]] = {i,++mp1[arr[i]][1],right[i]};
        }
        vector<long long> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = left[i]+right[i];   
        }
        return ans;
    }
};