class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int maxpro = 0;
        for(int i=1;i<prices.size();i++){
            maxpro = max(maxpro,prices[i]-min);
            min = prices[i]<min ? prices[i] : min ;
        }
        return maxpro;
    }
};