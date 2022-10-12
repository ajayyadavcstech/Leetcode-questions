class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a+b>c && a+c>b && b+c>a) return a+b+c;
        }
        return 0;
    }
};