class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> dublicate(nums.size()+1,0);
        for(auto i : nums){
            dublicate[i]++;
        }
        for(int i=0;i<dublicate.size();i++)
            if(dublicate[i]>1) return i;
        return -1;
    }
};