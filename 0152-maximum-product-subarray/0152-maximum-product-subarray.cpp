class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT32_MIN;
        int cur = 1;
        for(int i=0;i<nums.size();i++){
            cur*=nums[i];
            mx = max(mx,cur);
            if(cur==0) cur = 1;
        }
        cur = 1;
        for(int i=nums.size()-1;i>=0;i--){
            cur*=nums[i];
            mx = max(mx,cur);
            if(cur==0) cur = 1;
        }
        return mx;
    }
};