class Solution {
public:
    int jump(vector<int>& nums) {
        int stp = 0;
        int next_stp = 0;
        int min_stp = 0;
        for(int i=0;i<nums.size()-1;i++){
            next_stp = max(next_stp,nums[i]);
            if(stp==0){
                stp = next_stp;
                min_stp++;
            }
            stp--;
            next_stp--;
        }
        return min_stp;
    }
};