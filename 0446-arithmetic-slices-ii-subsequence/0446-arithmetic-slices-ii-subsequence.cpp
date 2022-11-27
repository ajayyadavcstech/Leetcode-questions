class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long,int>> ind_diff(n);
        int ans = 0;
        for(int i=0;i<n;i++){
            int cur = 0;
            for(int j=0;j<i;j++){
                long long diff = (long)nums[i]-nums[j];
                cur = cur + ind_diff[j][diff];
                ind_diff[i][diff]+=(ind_diff[j][diff]+1);
            }
            ans+=cur;
        }
        return ans;
    }
};