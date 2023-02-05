class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])==0) mp[nums[i]] = vector<int>(k,0);
            int ind = i%k;
            for(int j=0;j<k;j++){
                if((j*ind)%k==0) cnt+=mp[nums[i]][j];
            }
            mp[nums[i]][ind]++;
        }
        return cnt;
    }
};  
