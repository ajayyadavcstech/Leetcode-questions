class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mx(prices.size());
        mx[prices.size()-1]=0;
        for(int i=prices.size()-2;i>=0;i--){
           mx[i] = max(prices[i+1],mx[i+1]); 
        }
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            ans = max(ans,mx[i]-prices[i]);
        }
        return ans;
    }
};