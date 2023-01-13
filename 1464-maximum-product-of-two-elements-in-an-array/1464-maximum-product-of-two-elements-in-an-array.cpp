class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0;
        int mx2 = 0;
        for(auto &x:nums){
            if(x>mx1){
                mx2 = mx1;
                mx1 = x;
            }
            else{
                mx2 = max(mx2,x);
            }
        }
        return (mx1-1)*(mx2-1);
    }
};