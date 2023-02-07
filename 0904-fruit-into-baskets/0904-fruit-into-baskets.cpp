class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int ans = 0;
        int cnt = 0;
        int j = 0;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            cnt++;
            while(mp.size()>2){
                cnt--;
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0) mp.erase(fruits[j]);
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};