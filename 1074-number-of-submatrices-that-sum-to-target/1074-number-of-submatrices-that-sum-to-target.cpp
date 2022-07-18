class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                matrix[i][j] = matrix[i][j-1] + matrix[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<matrix[0].size();i++){
            for(int j=i;j<matrix[0].size();j++){
                unordered_map<int,int> mp;
                int sum = 0;
                mp[0] = 1;
                for(int p=0;p<matrix.size();p++){
                    sum+= (i==0?matrix[p][j]:matrix[p][j]-matrix[p][i-1]);
                    if(mp.find(sum-target)!=mp.end()) ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};