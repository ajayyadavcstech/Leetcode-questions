class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        int n = capacity.size();
        for(int i=0;i<n;i++){
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int cnt = 0;
        for(auto &x:capacity){
            if(x>add) break;
            cnt++;
            add-=x;
        }
        return cnt;
    }
};