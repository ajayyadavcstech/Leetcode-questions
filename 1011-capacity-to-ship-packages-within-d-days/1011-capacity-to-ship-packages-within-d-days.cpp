class Solution {
public:
    bool is_pos(vector<int> &nums,int weight,int n){
        int sum = 0;
        int cnt = 1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>weight){
                sum = nums[i];
                cnt++;
            }
            if(cnt>n) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 1;
        int e = 0;
        for(auto &x:weights){
            s = max(s,x);
            e+=x;
        } 
        int mx_weight;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(is_pos(weights,mid,days)){
                mx_weight = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return mx_weight;
    }
};