class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums) mp[x]++;
        unordered_map<int,int> ending;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0) continue;
            else if(ending[nums[i]-1]>0){
                mp[nums[i]]--;
                ending[nums[i]-1]--;
                ending[nums[i]]++;
            }
            else if(mp[nums[i]+1]>0 && mp[nums[i]+2]>0) {
                mp[nums[i]]--;
                mp[nums[i]+1]--;
                mp[nums[i]+2]--;
                ending[nums[i]+2]++;
            }
            else 
                return false;
        }
        return true;
    }
};