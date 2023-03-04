class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mn = -1;
        int mx = -1;
        long long cnt = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                mn = -1;
                mx = -1;
                j = i+1;
            }
            else{
                if(nums[i]==minK) mn = i;
                if(nums[i]==maxK) mx = i;
                if(mn!=-1 && mx!=-1){
                    cnt+=(min(mn,mx)-j+1);
                }
            }
        }
        return cnt;
    }
};

