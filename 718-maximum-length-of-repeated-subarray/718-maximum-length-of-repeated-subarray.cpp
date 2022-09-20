class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),0));
        int max_ans = 0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(i==0 || j==0) dp[i][j] = (nums1[i]==nums2[j]) ? 1 : 0;
                else dp[i][j] = (nums1[i]==nums2[j]) ? dp[i-1][j-1]+1 : 0;
                max_ans = max(max_ans,dp[i][j]);
            }
        }
        return max_ans;
    }
};