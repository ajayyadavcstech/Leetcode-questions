class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n,0);
        for(auto &x:roads){
            degree[x[0]]++;
            degree[x[1]]++;
        }
        sort(degree.begin(),degree.end());
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans+=(degree[i]*(i+1));
        }
        return ans;
    }
};