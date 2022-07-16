class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int mx=0;
        while(left<right){
            mx = max(mx,(right-left)*(min(height[left],height[right])));
            height[left]<height[right] ? left++ : right--;
        }
        return mx;
    }
};