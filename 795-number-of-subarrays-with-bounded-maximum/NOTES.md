Approach 1 :->  Brute force
```
class Solution {
public:
int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
int ans = 0;
for(int i=0;i<nums.size();i++){
int mx=INT32_MIN;
for(int j=i;j<nums.size();j++){
mx = max(mx,nums[j]);
if(mx>=left && mx<=right) ans++;
}
}
return ans;
}
};
```