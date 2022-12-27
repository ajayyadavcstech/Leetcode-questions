class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        vector<int> diff;
        for(int i=0;i<rocks.size();i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
        int ans = 0;
        for(auto &x:diff){
            if(x>add) break;
            ans++;
            add-=x;
        }
        return ans;
    }
};