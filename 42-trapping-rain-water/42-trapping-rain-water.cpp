class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = 0;
        int total_water = 0;
        for(int i=1;i<n;i++) left[i]= max(left[i-1],height[i-1]);
        for(int i=n-2;i>=0;i--) right[i] = max(right[i+1],height[i+1]);
        
        for(int i=0;i<n;i++){
            int Min = min(left[i],right[i]);
            total_water = total_water + (Min<=height[i] ? 0 : Min-height[i]);
        }
        return total_water;
    }
};