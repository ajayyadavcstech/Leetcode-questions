class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums[nums.size()-1] - nums[0];
        while(s<=e){
            int mid = s + (e-s)/2;
            int count = 0;
            int p1 = 0;
            int p2 = 0;
            while(p2<nums.size()){
                if(p1==p2) p2++;
                else if(nums[p2]-nums[p1] <=mid){
                    count+=(p2-p1);
                    p2++;
                }
                else {
                    p1++;
                }
            }
            if(count<k) s = mid + 1;
            else if(count>=k) e = mid - 1;
        }
        return s;
    }
};