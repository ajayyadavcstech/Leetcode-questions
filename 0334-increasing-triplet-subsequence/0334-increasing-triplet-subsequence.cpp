class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        map<int,int> right;
        map<int,int,greater<int>> left;
        for(auto &x:nums) right[x]++;
        for(auto&x:nums){
            left[x]++;
            auto p1 = left.lower_bound(x);
            auto p2 = right.lower_bound(x);
            p1++;
            p2++;
            if((p1)!=left.end() && (p2)!=right.end()) return true;
            right[x]--;
            if(right[x]==0) right.erase(x);
        }
        return false;
    }
};